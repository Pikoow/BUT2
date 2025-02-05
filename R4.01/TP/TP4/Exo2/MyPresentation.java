/**
 *	Le présentateur.
 */
public class MyPresentation {
	/** Le modèle. */
	private MyModel m_model;

	/** La vue. */
	private MyView m_view;

	/** Le service. */
	private final MyService m_service;

	/**
	 *	Constructeur.
	 */
	public MyPresentation() {
		this(new MyService());
	}
	
	/**
	 *	Constructeur.
	 */
	public MyPresentation(MyService _service) {
		m_service = _service;
	}
	
	/**
	 *	Mutateur.
	 *	@param _model Le modèle.
	 */
	public void setModel(MyModel _model) {
		m_model = _model;
	}
	
	/**
	 *	Mutateur.
	 *	@param _view La vue.
	 */
	public void setView(MyView _view) {
		m_view = _view;
	}
	
	/**
	 *	Dit bonjour.
	 */
	public void sayHello() {
		// TODO: On récupère les paramètres d'entrée
		String userName = m_view.getInput();
		// TODO: On modifie les données du modèle
		m_model.setName(userName);
		// TODO: On modifie le message dans la vue
		String message = "Bonjour, " + userName + "!";
		m_view.setMessage(message);
	}
}
