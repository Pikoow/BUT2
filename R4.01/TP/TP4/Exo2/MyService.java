/**
 *	Le service.
 */
public class MyService {
	/**
	 *	Envoie le message de bonjour.
	 *	@param _name
	 *	@return Le message de bonjour.
	 */
	public String sayHello(String _name) {
		if (_name.isEmpty()) {
			return "Bonjour inconnu" ;
		}
		return "Bonjour " + _name ;
	}
}
