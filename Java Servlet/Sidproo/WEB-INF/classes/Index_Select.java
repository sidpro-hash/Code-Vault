
import java.io.IOException;
import java.io.PrintWriter;


import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpSession;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.RequestDispatcher;

// First method of creating servlet
public class Index_Select extends HttpServlet{
	private String message;
	
	public void init() throws ServletException{
		message = "Collecting Employee information";
	}
	
	public void service(HttpServletRequest request,HttpServletResponse response) throws ServletException,IOException{
		response.setContentType("text/html");
		PrintWriter out = response.getWriter();
		String username = "";
		HttpSession session=request.getSession(false);  
		if(session==null){
			response.sendRedirect("Login");
		}else{
			username=(String)(session.getAttribute("username")==null?"":session.getAttribute("username"));
			if(username.equals("")){
					response.sendRedirect("Login");
			}
		}
		
		out.println("<!DOCTYPE html>");
		out.println("<html>");
		
		out.println("<head>");
			out.println("<title> Servlet By Sid </title>");
			out.println("<meta charset=\"utf-8\">");
			out.println("<meta name=\"author\" content=\"SidPro\"/>");
			out.println("<meta name=\"viewport\" content=\"width=device-width,initial-scale=1\">");
			out.println("<link type=\"text/css\" rel=\"stylesheet\" href=\"index_select.css\">");
			out.println("<script src=\"jquery-3.5.1.min.js\"></script>");
			out.println("<script src=\"index_select.js\"></script>");
			/*out.println("<script>");
			out.println("function CloseS(){");
			out.println("window.location.href=\"Logout\";}");
			out.println("</script>");*/
		out.println("</head>");
		
		out.println("<body>");
		out.println("<div class=\"topnav\">");
			out.println("<a class=\"active\" href=\"#home\">Home</a>");
			out.println("<a href=\"#About\">About</a>");
			out.println("<a href=\"Collect_Info\">Registration</a>");
			out.println("<a href=\"Logout\">Logout</a>");
		out.println("</div>");
		out.println("<h2 style=\"text-align:center\">"+username+" Click One of Below Given Link</h2>");
		out.println("<p style=\"text-align:center\"><a href=\"Collect_Info\">Employee Registration</a></p>");
		out.println("<p style=\"text-align:center\"><a href=\"Display_Info\">View Existing Records of Employee</a></p>");
		out.println("<button id=\"button4\">Stop</button><br>");
		out.println("<button id=\"button1\">hide links</button><br>");
		out.println("<button id=\"button2\">Play</button><br>");
		out.println("<button id=\"button3\">Boomerang</button>");
		out.println("<div id=\"div1\" style=\"width:80px;height:80px;display:none;background-color:yellow\"></div><br>");
		out.println("<div id=\"div2\" style=\"width:80px;height:80px;display:none;background-color:red\"></div><br>");
		out.println("<div id=\"div3\" style=\"width:80px;height:80px;display:none;background-color:blue;\"></div>");
		out.println("<div id=\"div4\" style=\"width:80px;height:80px;background-color:#ccc;position:absolute;\"></div>");

		out.println("</body>");
		out.println("</html>");
		 
	}
	
}