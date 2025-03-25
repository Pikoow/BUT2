import java.io.IOException;
import java.io.PrintWriter;

import jakarta.servlet.ServletException ;
import jakarta.servlet.annotation.WebServlet ;
import jakarta.servlet.http.HttpServlet ;
import jakarta.servlet.http.HttpServletRequest ;
import jakarta.servlet.http.HttpServletResponse ;

/**
 *	Le contrôleur.
 */
@WebServlet(
	urlPatterns = { "/hello" }, asyncSupported = true
)
public class MyServletHello extends HttpServlet {
	/**
	 * @see HttpServlet#doGet(HttpServletRequest _request, HttpServletResponse _response)
	 */
	@Override
	protected void doGet(HttpServletRequest _request, HttpServletResponse _response) throws ServletException, IOException {        
        String name = _request.getParameter("name");
        
        if (name == null || name.isEmpty()) {
            name = "World";
        }
        
        try (PrintWriter httpWriter = _response.getWriter()) {
            httpWriter.println("Hello " + name);
        }
	}
}
