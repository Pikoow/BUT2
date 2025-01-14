<?php
	// NB : C'est du quick and dirty. Pas de test si pb accès item inexistant
	$articles = json_decode(file_get_contents(__DIR__ . '/data.json'), true);

	function save($newData) {
		$filePath = __DIR__ . '/data.json';
	
		if (file_exists($filePath)) {
			$existingData = json_decode(file_get_contents($filePath), true);
			if (!is_array($existingData)) {
				$existingData = [];
			}
		} else {
			$existingData = [];
		}
	
		$existingData[] = $newData;
	
		$encodedData = json_encode($existingData, JSON_PRETTY_PRINT);
		file_put_contents($filePath, $encodedData);
	}
	

	$app->get('/', function($req, $resp) {
		return buildResponse($resp, 'Ca maaaaarche !');
	});

	$app->get('/articles', function($req, $resp) {
		global $articles;

		$ret = array();
		foreach ($articles as $key => $val) {
			$item = $val;
			$item['id'] = $key;
			$ret[] = $item;
		}
		return buildResponse($resp, $ret);
	});

	$app->get('/articles/{id}', function($req, $resp, $args) {
		global $articles;

		$id = $args['id'];
		$item = $articles[$id];
		$ret = $item;

		return buildResponse($resp, $ret);
	});

	$app->post('/articles', function ($req, $resp, $args) {
		global $articles;
	
		$params = $req->getParsedBody();
	
		save($params);
	
		$responseBody = $resp->getBody();
		$responseBody->write('Article ajouté avec succès.');
		return $resp->withStatus(200);

	});

	// Fix "bug" (?) avec PUT vide (body non parsé)
	$app->addBodyParsingMiddleware();
	$app->run();

?>
