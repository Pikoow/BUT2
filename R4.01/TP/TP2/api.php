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
	
	function saveAll($data) {
		$filePath = __DIR__ . '/data.json';
		$encodedData = json_encode($data, JSON_PRETTY_PRINT);
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
	
		return $resp->withStatus(200);
	});

	$app->put('/articles/{id}', function ($req, $resp, $args) {
		global $articles;
	
		$id = $args['id'];
		if (!isset($articles[$id])) {
			return $resp->withStatus(404)->write('Article not found');
		}
	
		$params = $req->getParsedBody();
		$articles[$id] = $params;
		saveAll($articles);
	
		return $resp->withStatus(200);
	});

	$app->patch('/articles/{id}', function ($req, $resp, $args) {
		global $articles;
	
		$id = $args['id'];
		if (!isset($articles[$id])) {
			return $resp->withStatus(404)->write('Article not found');
		}
	
		$params = $req->getParsedBody();
		$articles[$id] = array_merge($articles[$id], $params);
		saveAll($articles);
	
		return $resp->withStatus(200);
	});

	$app->delete('/articles/{id}', function ($req, $resp, $args) {
		global $articles;
	
		$id = $args['id'];
		if (!isset($articles[$id])) {
			return $resp->withStatus(404)->write('Article not found');
		}
	
		unset($articles[$id]);
		saveAll($articles);
	
		return $resp->withStatus(200);
	});

	// Fix "bug" (?) avec PUT vide (body non parsé)
	$app->addBodyParsingMiddleware();
	$app->run();
?>
