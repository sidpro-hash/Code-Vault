<!DOCTYPE html> 
 <html> 

 <head> 
	 <title> Jsp By Sid </title> 
	 <meta charset="utf-8"> 
	 <meta name="author" content="SidPro"/> 
	 <meta name="viewport" content="width=device-width,initial-scale=1"> 
	 <link type="text/css" rel="stylesheet" href="Collect_Info.css"> 
 </head> 

 <body> 
	<%
		String fname ="",lname="",pass="",enNo=""; 
		if(request.getAttribute("fname_error")!=null){
			fname=(String)request.getAttribute("fname_error");
			request.removeAttribute("fname_error");
		}
		if(request.getAttribute("lname_error")!=null){
			lname=(String)request.getAttribute("lname_error");
			request.removeAttribute("lname_error");
		}
		if(request.getAttribute("enNo_error")!=null){
			enNo=(String)request.getAttribute("enNo_error");
			request.removeAttribute("enNo_error");
		}
		if(request.getAttribute("pass_error")!=null){
			pass=(String)request.getAttribute("pass_error");
			request.removeAttribute("pass_error");
		}
	%>
	<h2>Collecting Employee information Of Collegeek</h2> 

	<form method="post" action="validate_user" class="main_container"> 
	<div class="containerbase"> 
		<lable id="F" for="firstname">Enter First Name :<%= fname %></lable><br> 
		<input type="text" name="firstName" id="firstname" placeholder="Enter your first name here"><br> 
		<lable id="L" for="lastname">Enter Last Name :<%= lname %></lable><br> 
		<input type="text" name="lastName" id="lastname" placeholder="Enter your last name here"><br> 
		<lable id="E" for="enNo">Enter Enrollment no :<%= enNo %></lable><br> 
		<input type="text" name="enNo" id="enNo" placeholder="Enter your Enrollment no here"><br> 
		<lable>Select Gender:</lable><br> 
		<input type="radio" name="gender" value="Male" checked>Male 
		<input type="radio" name="gender" value="Female">Female 
		<input type="radio" name="gender" value="other">other<br> 

		<lable id="P" for="Pass">Enter Password:<%= pass %></lable><br> 
		<input type="password" name="password" id="Pass" placeholder="Enter your password here"><br> 
		<div class="container"> 
		<input type="submit" value="Submit"><input type="reset" value="Reset"> 
		</div> 
	</div> 
	</form> 

	<section> 
		<div class="wave wave1"></div> 
		<div class="wave wave2"></div> 
		<div class="wave wave3"></div> 
	</section> 
</body> 
</html> 