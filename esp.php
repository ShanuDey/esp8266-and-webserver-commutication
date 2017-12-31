<?php 
print "id=";
$pot=$_GET['pot'];
include('dbcon.php');
$query1="UPDATE `iot` SET `pot`='$pot'";
$run1=mysqli_query($con,$query1);

$query1="SELECT `led` FROM `iot`";
$run1=mysqli_query($con,$query1);
$data=mysqli_fetch_assoc($run1);
print $data['led'].".";
?>