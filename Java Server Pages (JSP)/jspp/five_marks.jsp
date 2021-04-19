 <!DOCTYPE html> 
 <html> 

 <head> 
	 <title> Jsp By Sid </title> 
	 <meta charset="utf-8"> 
	 <meta name="author" content="SidPro"/> 
	 <meta name="viewport" content="width=device-width,initial-scale=1"> 
	 <link type="text/css" rel="stylesheet" href="Collect_Info.css"> 
	<style>
	  /* Chrome, Safari, Edge, Opera */
input::-webkit-outer-spin-button,
input::-webkit-inner-spin-button {
  -webkit-appearance: none;
  margin: 0;
}

/* Firefox */
input[type=number] {
  -moz-appearance: textfield;
}
input[type=number]{
    padding: 12px 16px;
    margin: 8px 0px;
    display:inline-block;
    border-radius: 5px;
    border:1px solid #ccc;
    box-sizing: border-box;
    width:100%;
  }
    input[type=number]:hover,input[type=number]:focus{
    background-color: lightgray;
    border-color:2px solid gray;
  }
	</style>
 </head> 

 <body> 
	
	<h2>Collecting Marks of students <br><a href="register_user.jsp" target="_self"> Register Here </a> | <a href="Logout.jsp"> Logout </a></h2> 
<%
			
			String username=(String)(session.getAttribute("username")==null?"":session.getAttribute("username"));
			if(username.equals("")){
					response.sendRedirect("Login.jsp");
			}else{
					out.println("<h3>UserName: "+username+"</h3>");
			}
%>
 <form method="post" action="grade.jsp" class="main_container"> 
 <div class="containerbase"> 
	 <lable id="F" for="ADJ">Enter Mark of Subject 1 :</lable><br> 
	 <input type="number" name="ADJ" id="ADJ" placeholder="Enter Mark of Advance Java Programming" min="0" max="100" required><br> 
	 <lable id="L" for="DM">Enter Mark of Subject 2 :</lable><br> 
	 <input type="number" name="DM" id="DM" placeholder="Enter Mark of Data mining" min="0" max="100" required><br> 
	 <lable id="F" for="TOC">Enter Mark of Subject 3 :</lable><br> 
	 <input type="number" name="TOC" id="TOC" placeholder="Enter Mark of Theory of Computation" min="0" max="100" required><br> 
	 <lable id="L" for="MPI">Enter Mark of Subject 4 :</lable><br> 
	 <input type="number" name="MPI" id="MPI" placeholder="Enter Mark of Microprocessor and Interfacing" min="0" max="100" required><br> 
	 <lable id="F" for="DV">Enter Mark of Subject 5 :</lable><br> 
	 <input type="number" name="DV" id="DV" placeholder="Enter Mark of Data visualization" min="0" max="100" required><br> 
	 
	 <div class="container"> 
	 <input type="submit" value="Submit"><input type="reset" value="Reset"> 
	 </div> 
 </div> 
 </form> 

 </body> 

 </html> 