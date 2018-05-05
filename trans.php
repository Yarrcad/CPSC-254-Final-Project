<html>
<body>

Transaction From: <?php echo $_POST["From"] ; ?><br>
Sent To:<?php echo $_POST["To"] ; ?><br>
Containing: <?php echo $_POST["Coins"] ; ?> Coins. <br>

<?php
$myfile = fopen("/mnt/c/Linux/HECKACOIN/transactionsreceived.txt", "a") or die("Unable to open file!");
fwrite($myfile, $_POST["From"]);
fwrite($myfile, " ");
fwrite($myfile, $_POST["To"]);
fwrite($myfile, " ");
fwrite($myfile, $_POST["Coins"]);
fwrite($myfile, " ");
fwrite($myfile, strval(time()));
fwrite($myfile, "\n");
close($myfile);
?>

<?php
system("/mnt/c/Linux/HECKACOIN/NodeMiner");
?>

</body>
</html>

