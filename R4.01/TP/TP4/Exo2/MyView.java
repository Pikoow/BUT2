import javafx.scene.control.TextField ;
import javafx.scene.control.Label ;
import javafx.event.ActionEvent ;
import javafx.fxml.* ;

/**
 *	La vue.
 */
public class MyView  {
	/** La présentation. */
	private MyPresentation m_presentation ;	
	
	// On récupère le champs de texte d'entrée du fichier myscreen.fxml
	/** L'entrée. */
	@FXML
	private TextField m_input ;
	/** La sortie. */
	@FXML
	private Label m_output ;

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
	 *	@param _presentation Le présentation.
	 */
	public void setPresentation(MyPresentation _presentation) {
		m_presentation = _presentation ;
	}
	
	/**
	 *	Met à jour le message.
	 *	@param _text Le message.
	 */
	public void setMessage(String _text) {
		// TODO: On modifie le message de sortie
		m_output.setText(_text);
	}
	
	/**
	 *	Dit bonjour.
	 */
	@FXML
	private void handleSayHello(ActionEvent _event) {
		// TODO: On délègue l'action à la présentation
		m_presentation.sayHello();
	}
}
