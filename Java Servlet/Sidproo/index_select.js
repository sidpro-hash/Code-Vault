window.oncontextmenu = (e) => {e.preventDefault();}
$(document).ready(function(){
  $("#button4").click(function(){
    $("#div1,#div2,#div3").stop();
  });
  $("#button1").click(function(){
    $("p").toggle();
  });
  $("#button2").click(function(){
    $("#div1").fadeToggle();
    $("#div2").fadeToggle("slow");
    $("#div3").fadeToggle(2000);
  });
  $("#button3").click(function(){
    $("#div4").animate({left:'250px'},"slow");
    $("#div4").animate({left:'10px'},"slow");
  });
  $("a").click(function(){
    $(this).addClass("active").siblings(this).removeClass("active")});
});
