import jakarta.servlet.ServletException;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;
import jakarta.servlet.http.HttpSession;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Date;
public class SessionTracking extends HttpServlet {
	private static final long serialVersionUID = 1L;
               public SessionTracking() {
        super();
        // TODO Auto-generated constructor stub
    }

		protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// Create a session object if it is already not  created. 
		HttpSession s1 = request.getSession(true); 
		// Get session creation time. 
		Date createTime = new Date(s1.getCreationTime()); 
		// Get last access time of this web page. 
		Date lastAccessTime = new Date(s1.getLastAccessedTime()); 
		@SuppressWarnings("removal")
		Integer visitCount = new Integer(0); 
		String visitCountKey = new String("visitCount"); 
		String userIDKey = new String("userID"); 
		String userID = new String("ABCD"); 
		// Check if this is new comer on your web page. 
		if (s1.isNew())  
		{ 
		s1.setAttribute(userIDKey, userID); 
		} 
		else 
		{ 
		visitCount = (Integer)s1.getAttribute(visitCountKey); 
		visitCount = visitCount + 1; 
		userID = (String)s1.getAttribute(userIDKey); 
		} 
		s1.setAttribute(visitCountKey,  visitCount); 
		// Set response content type
		response.setContentType("text/html"); 
		PrintWriter out = response.getWriter(); 
		out.println("<h1>session id is" + s1.getId() +  
		"<br>Creation Time"+ createTime +  
		"<br>last access time" + lastAccessTime +  
		"<br>User ID is" +userID +  
		"<br>Number of visits is" + 
		visitCount+"</h1>" ); 
		
	}
}
