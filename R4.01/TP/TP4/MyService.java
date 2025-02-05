/**
 *	Le service.
 */
public class MyService {
	/**
	 *	Dit bonjour.
	 *	@param _name Le nom.
	 *	@return Le message de bonjour.
	 */
	public String sayHello(String _name) {
		if (_name.isEmpty()) {
			return "Bonjour inconnu" ;
		}
		return "Bonjour " + _name ;
	}
}
