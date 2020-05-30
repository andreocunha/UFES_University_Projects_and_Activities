<?php

$coneccao = mysqli_connect("localhost", "root", "", "ufes");

// Check connection
if (mysqli_connect_errno()) {
    echo "Failed to connect to MySQL: " . mysqli_connect_error();
    exit();
}
  $nome = $_POST['nome'];
  $sobrenome = $_POST['sobrenome'];
  $email = $_POST['email'];
  $problema = $_POST['problema'];
  $predio = $_POST['predio'];
  $sala = $_POST['sala'];

// prepare and bind
$stmt = $coneccao->prepare("INSERT INTO problemas (nome, sobrenome, email, problema, predio, sala) VALUES (?, ?, ?, ?, ?, ?)");
$stmt->bind_param("sssssi", $nome, $sobrenome, $email, $problema, $predio, $sala);

$stmt->execute();
$insert = $stmt->get_result();
if(!$insert){
  echo '<script language="javascript" type="text/javascript">alert("Problema enviado");window.location.href="main-index.html";</script>';
}else{
  echo '<script language="javascript" type="text/javascript">alert("Não foi possivel enviar. Tente novamente.");window.location.href="main-index.html";</script>';
}

?>

