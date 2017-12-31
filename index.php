<?php include('dbcon.php'); ?>
<html>
	<head>
		<meta name="viewport" content="width=device-width,initial-scale=1,maximum-scale=1,user-scalable=no">
		<title>Shanu's Project</title>
	</head>
<body align="center">
<h1> Shanu</h1>
<form action="index.php" method="POST">
<table align="center" border="1">
	<tr>
		<td  align="center">id</td>
		<td  align="center">Led</td>
		<td  align="center">Pot</td>
	</tr>
<?php
$query ="SELECT * FROM `iot` WHERE 1";
$run = mysqli_query($con,$query);
$row=mysqli_num_rows($run);
if($row<1)
	{
		print "No row found";
	}
while($data=mysqli_fetch_assoc($run))
{
?>
	<tr>
		<td align="center"><?php print $data['id']; ?></td>
		<td align="center"><?php print $data['led']; ?><br>
			<input align="center" type="text"" name="led" placeholder=" 0 - 1023"><br>
			<button align="center" type="submit" value="<?php print $data['id']; ?>" name="id"> Change </button>
		</td>
		<td align="center"><?php print $data['pot']; ?></td>
	</tr>
<?php
}
?>
</form>
</table>
</body>
</html>
<?php
if(isset($_POST['id']))
{
	$id=$_POST['id'];
	$led=$_POST['led'];
	//print "id=".$id."\nled=".$led;
	$query1 ="UPDATE `iot` SET `led`='$led' WHERE `id`='$id'";
	$run1 = mysqli_query($con,$query1);
	?>
	<script type="text/javascript" >
		window.location.replace('index.php');
	</script>
	<?php
}
?>