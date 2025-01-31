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
		launch(_args);
	}
	
	/**
	 * @see Application#start(final Stage _primaryStage)
	 */
	@Override
	public void start(final Stage _primaryStage) throws Exception {
		FXMLLoader loader = new FXMLLoader(getClass().getResource("myscreen.fxml"));
        AnchorPane root = loader.load();
        Scene scene = new Scene(root);
        
        _primaryStage.setTitle("Hello JavaFX");
        _primaryStage.setScene(scene);
        _primaryStage.show();
	}
}
