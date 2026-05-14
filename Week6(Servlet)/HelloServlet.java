import jakarta.servlet.ServletException;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.io.PrintWriter;
public class HelloServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
    /**
   Default constructor. 
     */
    public HelloServlet() {
    }

protected void doGet(HttpServletRequest request, HttpServletResponse response) 
			throws ServletException, IOException {
		PrintWriter pw=response.getWriter();
		String s=request.getParameter("t1");
		pw.println("<h1>Hello,"+s);
		pw.close();
}
}
