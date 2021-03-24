
import java.io.IOException;
import java.io.PrintWriter;


import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.RequestDispatcher;

// First method of creating servlet
public class Login extends HttpServlet{
	private String message;
	
	public void init() throws ServletException{
		message = "Collecting Employee information";
	}
	
	public void service(HttpServletRequest request,HttpServletResponse response) throws ServletException,IOException{
		response.setContentType("text/html");
		PrintWriter out = response.getWriter();
		//String ppath = request.getContextPath();
		String fname ="";
		if(request.getAttribute("fname_error")!=null){
			fname=(String)request.getAttribute("fname_error");
			request.removeAttribute("fname_error");
		}
	
		out.println("<!DOCTYPE html>");
		out.println("<html>");
		
		out.println("<head>");
			out.println("<title> Servlet By Sid </title>");
			out.println("<meta charset=\"utf-8\">");
			out.println("<meta name=\"author\" content=\"SidPro\"/>");
			out.println("<meta name=\"viewport\" content=\"width=device-width,initial-scale=1\">");
			out.println("<link type=\"text/css\" rel=\"stylesheet\" href=\"Login.css\">");
		out.println("</head>");
		
		out.println("<body>");
			out.println("<div class=\"login\">");
			out.println("<h1>Login</h1>");
			out.println("<span style=\"color:#f24835\">"+fname+"</span>");
			out.println("<form action=\"Validation_Login\" method=\"post\">");
			out.println("<input type=\"text\" name=\"uname\" placeholder=\"Username\" required=\"required\" />");
			out.println("<input type=\"password\" name=\"pass\" placeholder=\"Password\" required=\"required\" />");
			out.println("<button type=\"submit\" class=\"btn btn-primary btn-block btn-large\">Let me in.</button>");
			out.println("<p>Don't have an account? <a href=\"/Sidpro/Collect_Info\" target=\"_self\">Sing up here!</a></p>");
			out.println("</form>");
			out.println("</div>");
		
		out.println("</body>");
		out.println("</html>");
		 
	}
	
}