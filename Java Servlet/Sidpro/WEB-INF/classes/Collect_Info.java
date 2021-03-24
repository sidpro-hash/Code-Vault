
import java.io.IOException;
import java.io.PrintWriter;


import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.RequestDispatcher;

// First method of creating servlet
public class Collect_Info extends HttpServlet{
	private String message;
	
	public void init() throws ServletException{
		message = "Collecting Employee information";
	}
	
	public void service(HttpServletRequest request,HttpServletResponse response) throws ServletException,IOException{
		response.setContentType("text/html");
		PrintWriter out = response.getWriter();
		//String ppath = request.getContextPath();
		String fname ="",lname="",pass="",email=""; 
		if(request.getAttribute("fname_error")!=null){
			fname=(String)request.getAttribute("fname_error");
			request.removeAttribute("fname_error");
		}
		if(request.getAttribute("lname_error")!=null){
			lname=(String)request.getAttribute("lname_error");
			request.removeAttribute("lname_error");
		}
		if(request.getAttribute("email_error")!=null){
			email=(String)request.getAttribute("email_error");
			request.removeAttribute("email_error");
		}
		if(request.getAttribute("pass_error")!=null){
			pass=(String)request.getAttribute("pass_error");
			request.removeAttribute("pass_error");
		}
	
		out.println("<!DOCTYPE html>");
		out.println("<html>");
		
		out.println("<head>");
			out.println("<title> Servlet By Sid </title>");
			out.println("<meta charset=\"utf-8\">");
			out.println("<meta name=\"author\" content=\"SidPro\"/>");
			out.println("<meta name=\"viewport\" content=\"width=device-width,initial-scale=1\">");
			out.println("<link type=\"text/css\" rel=\"stylesheet\" href=\"Collect_Info.css\">");
		out.println("</head>");
		
		out.println("<body>");
			out.println("<h2> "+message+"</h2>");
			//out.println("<h3>Myservlet extends HttpServlet</h3>");
			
		out.println("<form action=\"Validation_Info\" method=\"post\" class=\"main_container\">");
		out.println("<div class=\"containerbase\">");
			out.println("<lable for=\"firstname\">Enter First Name :"+fname+"</lable><br>");
			out.println("<input type=\"text\" name=\"fname\" id=\"firstname\" placeholder=\"Enter your first name here\"><br>");
			out.println("<lable for=\"lastname\">Enter Last Name :"+lname+"</lable><br>");
			out.println("<input type=\"text\" name=\"lname\" id=\"lastname\" placeholder=\"Enter your last name here\"><br>");
			out.println("<lable for=\"Email\">Enter Email:"+email+"</lable><br>");
			out.println("<input type=\"email\" name=\"email\" id=\"Email\" placeholder=\"Enter your email address here\"><br>");
			out.println("<lable for=\"exp\">Employee experience: </lable>");
			out.println("<select name=\"exp\" id=\"exp\">");
				out.println("<option value=\"1\">1</option>");
				out.println("<option value=\"2\">2</option>");
				out.println("<option value=\"3\">3</option>");
				out.println("<option value=\"4\" selected>4</option>");
				out.println("<option value=\"5\">5</option>");
				out.println("<option value=\"6\">6</option>");
				out.println("<option value=\"7\">7</option>");
				out.println("<option value=\"8\">8</option>");
			out.println("</select><br>");
			out.println("<lable>Select Gender:</lable><br>");
			out.println("<input type=\"radio\" name=\"gender\" value=\"Male\" checked>Male");
			out.println("<input type=\"radio\" name=\"gender\" value=\"Female\">Female");
			out.println("<input type=\"radio\" name=\"gender\" value=\"other\">other<br>");

			out.println("<lable for=\"Pass\">Enter Password:"+pass+"</lable><br>");
			out.println("<input type=\"password\" name=\"pass\" id=\"Pass\" placeholder=\"Enter your password here\"><br>");
			out.println("<div class=\"container\">");
			out.println("<input type=\"submit\" value=\"Submit\"><input type=\"reset\" value=\"Reset\">");
			out.println("</div>");
		out.println("</div>");
		out.println("</form>");
 
		out.println("<section>");
			out.println("<div class=\"wave wave1\"></div>");
			out.println("<div class=\"wave wave2\"></div>");
			out.println("<div class=\"wave wave3\"></div>");
		out.println("</section>");
		out.println("</body>");
		out.println("</html>");
		 
	}
	
}