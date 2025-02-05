import javafx.application.Application ;
import javafx.scene.Scene ;
import javafx.stage.Stage ;
import javafx.scene.layout.AnchorPane;
import javafx.fxml.FXMLLoader;

/**
 *	Le main.
 */
public final class MyApplication extends Application {
	/**
	 *	Lance l'application.
	 * 	@param _args Les arguments.
	 */
	public static void main(String[] _args) {
		launch(_args) ;
	}
	
	/**
	 *	Le point d’entrée de l’application.
	 *	@see Application#start(final Stage _stage)
	 */
	@Override
	public void start(final Stage _stage) throws Exception {
		_stage.setTitle("JavaFX Model-View-Controller (MVC)") ;
		FXMLLoader loader = new FXMLLoader(getClass().getResource("myscreen.fxml")) ;
		
		// On charge la racine de l’interface graphique de myscreen.fxml
		AnchorPane root = (AnchorPane) loader.load() ;

		// On récupère la classe de contrôle qui est aussi... la classe qui encapsule la vue
		MyView view = loader.getController() ;
		
		// On définit l’ensemble des classes de l’architecture MVC
		// C’est là qu’il va falloir travailler !

		// On crée le modèle...
		MyModel model = new MyModel() ;
		// TODO: ... et les dépendances avec la vue...
		view.setModel(model);
		
		// On crée le contrôleur...
		MyController controller = new MyController() ;
		// TODO: ... et les dépendances avec la vue et le modèle...
		controller.setView(view);
        controller.setModel(model);

		view.setController(controller);
		
		// On crée la scène à partir de la racine de l’interface graphique et on montre la fenêtre
		Scene scene = new Scene(root, 400, 120) ;
		_stage.setScene(scene) ;
		_stage.show() ;
	}
}
