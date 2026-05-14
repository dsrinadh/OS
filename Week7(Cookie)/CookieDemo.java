import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.Cookie;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.io.PrintWriter;
public class CookiesDemo extends HttpServlet {
	private static final long serialVersionUID = 1L;
              public CookiesDemo() {
        super();
        // TODO Auto-generated constructor stub
    }
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// Create cookies for first and last names.       
		Cookie firstName = new Cookie("first_name", 
		request.getParameter("first_name")); 
		Cookie lastName = new Cookie("last_name", 
		request.getParameter("last_name")); 
		// Set expiry date for both the cookies. 
		firstName.setMaxAge(60);   // 1min-60secs 
		lastName.setMaxAge(60*60*2); // 2hrs 
		// Add both the cookies in the response header. 
		response.addCookie( firstName ); 
		response.addCookie( lastName ); 
		// Set response content type 
		response.setContentType("text/html"); 
		PrintWriter out = response.getWriter(); 
		out.println("<b> Cookies are created and the cookies are:<b><br>"); 
		out.println("<b>First Name</b>: " 
		+ request.getParameter("first_name") + "\n" 
		+ " <b>Last Name</b>: " 
		+ request.getParameter("last_name") + "\n");
	}
}
