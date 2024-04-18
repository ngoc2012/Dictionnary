<?php 
//php query parameters url
$dict = $_GET['d'];
$word = urldecode($_GET['w']);
$suggest = $_GET['s'];
if ($word!=''){
	if ($dict!='0'&$dict!='4') {$f=fopen('word','w');fwrite($f,$word);fclose($f);$word="a";}
	else {$word = str_replace(" ","=",$word);}
	exec("dict.exe ".$dict." ".$word." ".$suggest,$result);
	for ($i=0;$i<count($result);$i++) {echo $result[$i];}
}
?>