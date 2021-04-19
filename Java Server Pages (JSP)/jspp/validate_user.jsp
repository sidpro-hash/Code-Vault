
<%@ page import="java.util.regex.Pattern" %>
<%@ page import="sidpro.Register_user" %>
<%
		String fname = ((request.getParameter("firstName")!=null)?request.getParameter("firstName"):"");
		String lname = (request.getParameter("lastName")==null)?"":request.getParameter("lastName");
		String enNo = (request.getParameter("enNo")==null)?"":request.getParameter("enNo");
		String pass = (request.getParameter("password")==null)?"":request.getParameter("password");
		String gender = request.getParameter("gender");
		
		boolean go = true;
			if(fname.equals("")){
				go=false;
				request.setAttribute("fname_error", "<span style=\"color:red;\"> * First Name is Required!</span>");
			}
			else{
				if(!Pattern.matches("^[a-zA-Z]*$",fname)){
					go=false;
					request.setAttribute("fname_error", "<span style=\"color:red;\"> * Only letters and white space allowed!</span>");
				}
			}
			
			if(lname.equals("")){
				go=false;
				request.setAttribute("lname_error", "<span style=\"color:red;\"> * Last Name is Required!</span>");
			}
			else{
				if(!Pattern.matches("^[a-zA-Z]*$",lname)){
					go=false;
					request.setAttribute("lname_error", "<span style=\"color:red;\"> * Only letters and white space allowed!</span>");
				}
			}
			
			if(pass.equals("")){
				go=false;
				request.setAttribute("pass_error", "<span style=\"color:red;\"> * Password is Required!</span>");
			}else{
				if(pass.length()<8){
					go=false;
					request.setAttribute("pass_error", "<span style=\"color:red;\"> * Password length must be 8 !</span>");
				}
			}
			
			if(enNo.equals("")){
				go=false;
				request.setAttribute("enNo_error", "<span style=\"color:red;\"> * Enrollment no is Required!</span>");
			}
			else{
				if(!Pattern.matches("^[0-9]{12}$",enNo)){
					go=false;
					request.setAttribute("enNo_error", "<span style=\"color:red;\"> * Invalid Enrollment no format!</span>");
				}
			}
		
			if(go){ %>
						<jsp:useBean id="userBean" class="sidpro.StudentBean">
						<jsp:setProperty name="userBean" property="*"/>
						</jsp:useBean>
<% 								 
				int status=Register_user.register(userBean);  
				if(status>0)  out.println("You are successfully registered"); 
				response.sendRedirect("Login.jsp");
			}else{	%>
				<jsp:include page="register_user.jsp"/>    
<%			}	
%>
