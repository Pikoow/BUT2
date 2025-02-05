import javafx.scene.control.TextField ;
import javafx.scene.control.Label ;

import javafx.event.ActionEvent ;
import javafx.fxml.* ;

/**
 *	La vue.
 */
public class MyView {
	/** Le modèle. */
	private MyModel m_model ;

	/** Le contrôleur. */
	private MyController m_controller ;
	
	// On récupère le champs de texte d'entrée du fichier myscreen.fxml
	/** L'entrée. */
	@FXML
	private TextField m_input ;

	// On récupère le label de sortie du fichier myscreen.fxml
	/** L'entrée. */
	@FXML
	private Label m_output ;

	/**
	 *	Réagit à l'action de l'utilisateur.
	 */
	@FXML
	private void handleSayHello(ActionEvent _event) {
		// TODO: On délègue l'action au contrôleur
		m_controller.sayHello();
	}
	
	/**
	 *	Met à jour la sortie.
	 */
	public void update() {
		// TODO: On change le contenu du label de sortie à partir du message du modèle
		m_output.setText(m_model.getMessage());
	}
	
	/**
	 *	Accesseur.
	 *	@return Le texte d'entrée.
	 */
	public String getInput() {
		// TODO: On récupère les paramètres d'entrée à partir du nom du champ de texte 
		return m_input.getText();
	}
	
	/**
	 *	Mutateur.
	 *	@param _model Le modèle.
	 */
	public void setModel(MyModel _model) {
		m_model = _model ;
	}
	
	/**
	 *	Mutateur.
	 *	@param _controller Le contrôleur.
	 */
	public void setController(MyController _controller) {
		m_controller = _controller ;
	}
}
