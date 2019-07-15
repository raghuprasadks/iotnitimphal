char MyWebPage[] PROGMEM = R"=====(
<!DOCTYPE html>
<html lang="en">
<head>
<title>SECURE EMBEDDED SERVER</title>
<meta charset="utf-8">
<meta name="viewport" content="width=device-width, initial-scale=1">
<style>
* {
  box-sizing: border-box;
}
body {
  font-family: Arial, Helvetica, sans-serif;
  background: #fff;;
}
header {
  background-color: #07816b;
  padding: 30px;
  font-size: 20px;
  color: white;
}
nav {
  float: left;
  width: 30%;
  height: 300px;
  background-color: #500000;
  padding: 20px;
}
nav ul {
  list-style-type: none;
  padding: 0;
}
article {
  color: white;
  float: left;
  padding: 20px;
  width: 70%;
  background-color: #500000;
  height: 300px;
}
section:after {
  content: "";
  display: table;
  clear: both;
}
footer {
  background-color: #777;
  padding: 10px;
  text-align: center;
  color: white;
}
@media (max-width: 600px) {
  nav, article {
    width: 100%;
    height: auto;
  }
}
</style>
</head>
<body>
<h2>SECURE IOT SERVER USING NODE MCU</h2>
<p>In this example, We can Monitor the Sensor Value Data, and controls all the electronic components </p>
<p>This Web pages is created using simple html,css, ajax and java scripts</p>
<header>
  <div>
  <p>SWITCH 1 STATUS: <span id="switch1-state">___</span></p>
  <button onclick="myFunction1()"> SWITCH </button>
  <p>SWITCH 2 STATUS: <span id="switch2-state">___</span></p>
  <button onclick="myFunction2()"> SWITCH </button>
  </div>
  <div>
  <h6 style="font-size: 20px;">SENSOR DATA:<span id="SENSOR1Value" style="color: red;">0</span>  This is the data reading from the sensor</h6>
  </div>
</header>
<section>
  <nav>
  </nav>
  
  <article>
    <h1>Internet Of Things(IOT)</h1>
    <p>The Internet of things (IoT) is the extension of Internet connectivity into physical devices and everyday objects. Embedded with electronics, Internet connectivity,</p>
    <p>and other forms of hardware (such as sensors), these devices can communicate and interact with others over the Internet, and they can be remotely monitored and controlled.</p>
    <p>The IoT concept has faced prominent criticism, especially in regards to privacy and security concerns related to these devices and their intention of pervasive presence.</p>
  </article>
</section>
<footer>
  <p>TLS/SSL Embedded Servers Presented By Edulife India Banglore</p>
</footer>
</body>
<script>
function myFunction1()
{
  console.log("button 1 was clicked");
  var xmlRequest = new XMLHttpRequest();
  var url1 = "/switch1state";
  xmlRequest.onreadystatechange = function() {
    if(this.readyState == 4 && this.status == 200)
    {
      document.getElementById("switch1-state").innerHTML = this.responseText;
    }
  };
  xmlRequest.open("GET",url1,true);
  xmlRequest.send();  
};
document.addEventListener('DOMContentLoaded', myFunction1, false);

function myFunction2()
{
  console.log("button 2 was clicked");
  var xmlRequest = new XMLHttpRequest();
  var url2 = "/switch2state";
  xmlRequest.onreadystatechange = function() {
    if(this.readyState == 4 && this.status == 200)
    {
      document.getElementById("switch2-state").innerHTML = this.responseText;
    }
  };
  xmlRequest.open("GET",url2,true);
  xmlRequest.send();  
};
document.addEventListener('DOMContentLoaded', myFunction2, false);

setInterval(function() {
  // Call a function repetatively with 2 Second interval
  getData();
}, 1000); //2000mSeconds update rate
 
function getData() {
  var xhttp = new XMLHttpRequest();
  var url3 = "/readSensor1";
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("SENSOR1Value").innerHTML =
      this.responseText;
    }
  };
  xhttp.open("GET",url3, true);
  xhttp.send();
}
</script>
</html>
)=====";
