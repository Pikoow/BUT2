/**
 *	Le contrôleur.
 */
public class MyController {
	/** Le modèle. */
	private MyModel m_model ;

	/** La vue. */
	private MyView m_view ;
	
	/**
	 *	Dit bonjour.
	 */
	public void sayHello() {
		// TODO: On récupère les paramètres d'entrée
		String name = m_view.getInput();
		// TODO: On modifie les données du modèle
		m_model.setName(name);

		m_view.update();
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
	 *	@param _view La vue.
	 */
	public void setView(MyView _view) {
		m_view = _view ;
	}
}
