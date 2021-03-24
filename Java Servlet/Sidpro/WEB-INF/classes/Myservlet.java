
import java.io.IOException;
import java.io.PrintWriter;


import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

// First method of creating servlet
public class Myservlet extends HttpServlet{
	private String message;
	
	public void init() throws ServletException{
		message = "Welcome you all to Collegeek.com";
	}
	
	public void doGet(HttpServletRequest request,HttpServletResponse response) throws ServletException,IOException{
		response.setContentType("text/html");
		PrintWriter out = response.getWriter();
		
		out.println("<!DOCTYPE html>");
		out.println("<html>");
		out.println("<head>");
		out.println("<title> Servlet By Sid </title>");
		out.println("<meta charset=\"utf-8\">");
		out.println("<meta name=\"author\" content=\"SidPro\"/>");
		out.println("</head>");
		out.println("<body>");
		out.println("<h1> "+message+"</h1>");
		out.println("<h3>Myservlet extends HttpServlet</h3>");
		out.println("<p>Collegeek is online learning platform where we consistently strive to offer the best of education</p>");
		out.println("<p>Let's Go To <a href=\"https://collegeek.com/\" target=\"_blank\">collegeek.com</a><p>");
		out.println("</body>");
		out.println("</html>");
	}
	
}