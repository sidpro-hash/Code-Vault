
import java.io.IOException;
import java.io.PrintWriter;


import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpSession;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.RequestDispatcher;

/**
*
* A class for Logout.
* Simply it destroy a session.
*
*
* @author  Siddharth Gabu
* @version 1.0
* @since   2021-03-25
*
*
*/


// First method of creating servlet
public class Logout extends HttpServlet{
	private String message;
	
	public void init() throws ServletException{
		message = "Logout Employee";
	}
	
	public void service(HttpServletRequest request,HttpServletResponse response) throws ServletException,IOException{
		response.setContentType("text/html");
		PrintWriter out = response.getWriter();
		
		
		
		HttpSession session=request.getSession(false);  
		if(session==null){
			response.sendRedirect("Login");
		}else{
			session.invalidate();
		}
		
			//RequestDispatcher rd=request.getRequestDispatcher("Login");
			//rd.forward(request,response);	
			response.sendRedirect("Login");
	}
	
}