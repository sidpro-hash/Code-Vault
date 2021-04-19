 <!DOCTYPE html> 
 <html> 

 <head> 
	 <title> Jsp By Sid </title> 
	 <meta charset="utf-8"> 
	 <meta name="author" content="SidPro"/> 
	 <meta name="viewport" content="width=device-width,initial-scale=1"> 
	 <link type="text/css" rel="stylesheet" href="Collect_Info.css"> 
	 <link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.1.3/css/bootstrap.min.css" 
	 integrity="sha384-MCw98/SFnGE8fJT3GXwEOngsV7Zt27NXFoaoApmYm81iuXoPkFOJwJ8ERdknLPMO" crossorigin="anonymous">
 </head> 

 <body> 
	
	<h2>Grades <br><a href="register_user.jsp" target="_self"> Register Here </a> | <a href="Logout.jsp"> Logout </a></h2> 
	<%
			String username=(String)(session.getAttribute("username")==null?"":session.getAttribute("username"));
			if(username.equals("")){
					response.sendRedirect("Login.jsp");
			}else{
					out.println("<h3>UserName: "+username+"</h3>");
			}
   
		int s[] = new int[5];
		String name[] = {"ADJ","DM","TOC","MPI","DV"};
		s[0] = Integer.valueOf( (request.getParameter("ADJ")==null?"0":request.getParameter("ADJ")) );
		s[1] = Integer.valueOf( (request.getParameter("DM")==null?"0":request.getParameter("DM")) );
		s[2] = Integer.valueOf( (request.getParameter("TOC")==null?"0":request.getParameter("TOC")) );
		s[3] = Integer.valueOf( (request.getParameter("MPI")==null?"0":request.getParameter("MPI")) );
		s[4] = Integer.valueOf( (request.getParameter("DV")==null?"0":request.getParameter("DV")) );
		
		out.println("<table class=\"table table-dark\">");
		out.print("<tr>");
		out.print("<th>Subject</th><th>Grades</th>");
		out.println("</tr>");

		for(int i=0;i<5;++i){
			String l = "";
			if(s[i]>=85)l="AA";
			else if(s[i]>=75)l="AB";
			else if(s[i]>=65)l="BB";
			else if(s[i]>=55)l="BC";
			else if(s[i]>=45)l="CC";
			else if(s[i]>=40)l="CD";
			else if(s[i]>=35)l="DD";
			else l = "FF";
			out.print("<tr>");
			out.print("<td>"+name[i]+"</td><td>"+l+"</td>");
			out.println("</tr>");
		}
		out.println("<tr><td>GTU</td><td>sucess is inevitable ha..ha..ha..!!!<td></tr>");
		out.println("</table>");
	%>
 </body> 

 </html> 