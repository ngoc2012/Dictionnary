<?php 
//php query parameters url
$dict = $_GET['d'];
$word = urldecode($_GET['w']);
$suggest = $_GET['s'];
if ($word!=''){
/*	if ($dict!='0'&$dict!='4') {$f=fopen('word','w');fwrite($f,$word);fclose($f);$word="a";}
	else {$word = str_replace(" ","=",$word);}
	exec("http://anhphapviet.com/dict.exe ".$dict." ".$word." ".$suggest,$result);
	for ($i=0;$i<count($result);$i++) {echo $result[$i];}
*/
}
?>

Bonjour, Je me suis inscris � 1&1 Essentiel pour monter un dictionnaire sur mon site. 
Jai programm� une programme Windows en C++ (fichier *.exe) pour chercher les donn�es dans les fichiers dictionnaires. Et le ficher php va ex�cuter ce fichier *.exe.exec(http://anhphapviet.com/dict.exe,$results). Mon site marche bien en local (localhost WAMP), mais il ne marche pas sur votre serveur. Je voudrais savoir si il y a des restrictions sur ex�cution des fichier .exe et �criture des fichiers de type texte sur votre serveur. Cordialement

Bonjour, Je me suis inscris � 1&1 Essentiel pour monter un dictionnaire sur mon site. 
J'ai programm� une programme Windows en C++ (fichier *.exe) pour chercher les donn�es dans les fichiers dictionnaires. Et le ficher php va ex�cuter ce fichier *.exe.
exec(http://anhphapviet.com/dict.exe,$results). Mon site marche bien en local (localhost WAMP), mais il ne marche pas sur votre serveur. Je voudrais savoir s'il y a des restrictions sur l'ex�cution des fichier .exe et l'�criture des fichiers de type "texte" sur votre serveur. Cordialement

Bonjour,
Je me suis inscris � 1&1 Essentiel pour monter un dictionnaire sur mon site. 

J'ai programm� une programme Windows en C++ (fichier *.exe) pour chercher les donn�es dans les fichiers dictionnaires. 

Et le ficher php va ex�cuter ce fichier *.exe.
exec("http://anhphapviet.com/dict.exe",$results)

Mon site marche bien en local (localhost WAMP), mais il ne marche pas sur votre serveur.

Je voudrais savoir s'il y a des restrictions sur l'ex�cution des fichier .exe et l'�criture des fichiers de type "texte" sur votre serveur.

Cordialement