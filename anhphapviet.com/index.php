<!doctype html><html><head><meta http-equiv="content-type" content="text/html; charset=UTF-8"><meta name='keywords' content='dictionary,vietnamese,tieng viet,english,tieng anh,french,tieng phap,vietnamese dictionary,tu dien,tra tu,anh viet,phap viet,language,ngon ngu,vietnam,viet nam,translate,translation'>
<TITLE>Tu dien Anh Phap Viet</TITLE>
<script type="text/javascript" src="vime.js"></script>
<link type="text/css" href="style.css" rel="stylesheet"/>
</head>
<body onload="load()">
<div id="wrapper">
	<div id="header">
		Từ điển Anh-Pháp-Việt siêu tốc
	</div>
	<table>
		<tr>
			<td><input type="button" value="Tìm" style="width:120px" onclick="getword(0)"/></td><td><input type="button" value="G" style="width:40px"class="b"onclick="googleSearch()"/></td>
			<td align = center><img src="book.gif"/></td>
			<td align = center>V</td>
			<td><div id="login"></div></td>
		</tr>
		<tr>
			<td colspan="2"><input type="text" maxlength=20 size=20 id="word" value="" class="t" onkeyup="keypress(this)"/></td>
			<td><select id="dic" style="background-color:#000000;color:white;font-family:monospace;" onchange="dict()">
				<option value="1">En-Vn</option>
				<option value="2">Vn-En</option>
				<option value="3">Fr-Vn</option>
				<option value="4">Vn-Fr</option>
				<option value="5">En-En</option>
				<option value="6">Fr-Fr</option>
			</select></td>
			<td><input type="checkbox" id="telex" onclick="telex()"/></td>
			<td><div id="signup"></div></td>
		</tr>
	</table>
	<div id="mean"></div>
</div><!-- END wrapper-->
<script type="text/javascript">
var g_vietTyper = new VietIME();
document.getElementById("word").onkeypress = function( evt ) { g_vietTyper.targetOnKeyPress( evt, this );}
var xmlhttp = false;
try { xmlhttp = new ActiveXObject("Msxml2.XMLHTTP"); } catch (e) { try {xmlhttp = new ActiveXObject("Microsoft.XMLHTTP");} catch (E) {xmlhttp = false;}}
if (!xmlhttp && typeof XMLHttpRequest != 'undefined') {xmlhttp = new XMLHttpRequest();}
document.getElementById("word").focus();
function getword(s) {
	var word = document.getElementById("word").value;
	var obj = document.getElementById("mean");
	if (word==""){obj.innerHTML ="";return false;}
	var selectValue = document.getElementById("dic").selectedIndex;
	xmlhttp.open("GET","dict.php"+"?d="+selectValue+"&w="+encodeURIComponent(word)+"&s="+s);
	xmlhttp.onreadystatechange = function() {
		if (xmlhttp.readyState == 4 && xmlhttp.status == 200) { 
		obj.innerHTML = xmlhttp.responseText;
		}
	}
	xmlhttp.send(null);
	document.getElementById("word").focus(); 
}
function keypress(e) {
	var k = (window.event) ? window.event.keyCode : e.which;
	if (k==13){getword(0);document.getElementById("word").select();}else{getword(1);}
}
function dict() {
	var dic = document.getElementById("dic").selectedIndex;
	setCookie("dict",dic,365);
	kb(dic);
	getword(0);
	document.getElementById("word").focus(); 
	document.getElementById("word").select(); 
}
function telex(){
	setCookie("telex",document.getElementById("telex").checked,365);
	kb(document.getElementById("dic").selectedIndex);
	document.getElementById("word").focus(); 
}
function setCookie(c_name,value,exdays) {
	var exdate=new Date();
	exdate.setDate(exdate.getDate() + exdays);
	var c_value=escape(value) + "; expires="+exdate.toUTCString();
	document.cookie=c_name + "=" + c_value;
}
function getCookie(c_name) {
	var i,x,y,ARRcookies=document.cookie.split(";");
	for (i=0;i<ARRcookies.length;i++) {
		x=ARRcookies[i].substr(0,ARRcookies[i].indexOf("="));
		y=ARRcookies[i].substr(ARRcookies[i].indexOf("=")+1);
		x=x.replace(/^\s+|\s+$/g,"");
		if (x==c_name) { return unescape(y); }
	}
}
function checkCookie() {
	var obj = document.getElementById("telex");
	var dict=getCookie("dict");
	if (dict!=null && dict!="") {
		document.getElementById("dic").selectedIndex = dict;
	}
	var tx=getCookie("telex");
	if (tx!=null && tx!="") {if(tx=="true"){obj.checked=true;}else{obj.checked=false;}}
}
function load(){
	checkCookie();
	kb(document.getElementById("dic").selectedIndex);
	//checkid(false);
	document.getElementById("word").focus(); 
}
function read(w){
	var word = w.innerHTML;
	document.getElementById("word").value = word;
	getword(0);
	document.getElementById("word").select(); 
}
function kb(dict) {
	var telex = document.getElementById("telex");
	switch(dict){
		case 0:
		case 4:
			telex.checked = false;
			g_vietTyper.setNormalMode();
			break;
		case 1:
		case 3:
			telex.checked = true;
			g_vietTyper.setTelexMode();
			break;
		default:
			if(document.getElementById("telex").checked) {g_vietTyper.setTelexMode();} else {g_vietTyper.setNormalMode();}
			break;
	}
}
function googleSearch() {
	var word = document.getElementById("word").value;
	if (word!="") {    
		window.open("http://www.google.com/images?hl=en&q=" + word);        
	}
}
</script>
</BODY>
</HTML>