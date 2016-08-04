/**
 * Created by zh on 2015/10/18.
 */
var li = document.getElementsByTagName("li");
var detaildiv = document.createElement("div");
detaildiv.style.width = "180px";
detaildiv.id = "detail";
detaildiv.style.backgroundColor = "#edf4fa";
detaildiv.style.textAlign="center";
detaildiv.style.fontSize="14px";
detaildiv.style.marginBottom="3px";
detaildiv.style.lineHeight="24px";
detaildiv.style.height = "24px";
detaildiv.style.border = "1px solid #bdd7ee";
detaildiv.style.position = "absolute";

/*background:#edf4fa;
border:1px solid #bdd7ee;
text-align:center;
font-size:14px;
width:130px;
height:24px;
line-height:24px;
margin-bottom:3px;
color:#666;*/



function mouseover1(demo) {



  detaildiv.innerHTML = "联系方式：18801770111";
  document.body.appendChild(detaildiv);
  document.getElementById("detail").style.display = "block";
    detaildiv.style.left = demo.getBoundingClientRect().left+135+"px";
    detaildiv.style.top = demo.getBoundingClientRect().top+"px";
    console.log(demo.currentStyle); console.log(demo.getBoundingClientRect().left);

}

function mouseover2(demo) {



  detaildiv.innerHTML = "联系方式：19215316542";
  document.body.appendChild(detaildiv);
  document.getElementById("detail").style.display = "block";
  detaildiv.style.left = demo.getBoundingClientRect().left+135+"px";
  detaildiv.style.top = demo.getBoundingClientRect().top+"px";
  console.log(demo.currentStyle); console.log(demo.getBoundingClientRect().left);

}
function mouseover3(demo) {



  detaildiv.innerHTML = "联系方式：18017569253";
  document.body.appendChild(detaildiv);
  document.getElementById("detail").style.display = "block";
  detaildiv.style.left = demo.getBoundingClientRect().left+135+"px";
  detaildiv.style.top = demo.getBoundingClientRect().top+"px";
  console.log(demo.currentStyle); console.log(demo.getBoundingClientRect().left);

}
function mouseover4(demo) {



  detaildiv.innerHTML = "联系方式：14526898654";
  document.body.appendChild(detaildiv);
  document.getElementById("detail").style.display = "block";
  detaildiv.style.left = demo.getBoundingClientRect().left+135+"px";
  detaildiv.style.top = demo.getBoundingClientRect().top+"px";
  console.log(demo.currentStyle); console.log(demo.getBoundingClientRect().left);

}
function mouseover5(demo) {



  detaildiv.innerHTML = "联系方式：74568932516";
  document.body.appendChild(detaildiv);
  document.getElementById("detail").style.display = "block";
  detaildiv.style.left = demo.getBoundingClientRect().left+135+"px";
  detaildiv.style.top = demo.getBoundingClientRect().top+"px";
  console.log(demo.currentStyle); console.log(demo.getBoundingClientRect().left);

}
function mouseover6(demo) {



  detaildiv.innerHTML = "联系方式：15236952146";
  document.body.appendChild(detaildiv);
  document.getElementById("detail").style.display = "block";
  detaildiv.style.left = demo.getBoundingClientRect().left+135+"px";
  detaildiv.style.top = demo.getBoundingClientRect().top+"px";
  console.log(demo.currentStyle); console.log(demo.getBoundingClientRect().left);

}
function mouseover7(demo) {



  detaildiv.innerHTML = "联系方式：5256";
  document.body.appendChild(detaildiv);
  document.getElementById("detail").style.display = "block";
  detaildiv.style.left = demo.getBoundingClientRect().left+135+"px";
  detaildiv.style.top = demo.getBoundingClientRect().top+"px";
  console.log(demo.currentStyle); console.log(demo.getBoundingClientRect().left);

}
function mouseover8(demo) {



  detaildiv.innerHTML = "联系方式：2513";
  document.body.appendChild(detaildiv);
  document.getElementById("detail").style.display = "block";
  detaildiv.style.left = demo.getBoundingClientRect().left+135+"px";
  detaildiv.style.top = demo.getBoundingClientRect().top+"px";
  console.log(demo.currentStyle); console.log(demo.getBoundingClientRect().left);

}
function mouseover9(demo) {



  detaildiv.innerHTML = "联系方式：569";
  document.body.appendChild(detaildiv);
  document.getElementById("detail").style.display = "block";
  detaildiv.style.left = demo.getBoundingClientRect().left+135+"px";
  detaildiv.style.top = demo.getBoundingClientRect().top+"px";
  console.log(demo.currentStyle); console.log(demo.getBoundingClientRect().left);

}
function mouseover10(demo) {



  detaildiv.innerHTML = "联系方式：165";
  document.body.appendChild(detaildiv);
  document.getElementById("detail").style.display = "block";
  detaildiv.style.left = demo.getBoundingClientRect().left+135+"px";
  detaildiv.style.top = demo.getBoundingClientRect().top+"px";
  console.log(demo.currentStyle); console.log(demo.getBoundingClientRect().left);

}
function mouseover11(demo) {



  detaildiv.innerHTML = "联系方式：1984";
  document.body.appendChild(detaildiv);
  document.getElementById("detail").style.display = "block";
  detaildiv.style.left = demo.getBoundingClientRect().left+135+"px";
  detaildiv.style.top = demo.getBoundingClientRect().top+"px";
  console.log(demo.currentStyle); console.log(demo.getBoundingClientRect().left);

}
function mouseover12(demo) {



  detaildiv.innerHTML = "联系方式：4798161";
  document.body.appendChild(detaildiv);
  document.getElementById("detail").style.display = "block";
  detaildiv.style.left = demo.getBoundingClientRect().left+135+"px";
  detaildiv.style.top = demo.getBoundingClientRect().top+"px";
  console.log(demo.currentStyle); console.log(demo.getBoundingClientRect().left);

}
function mouseover13(demo) {



  detaildiv.innerHTML = "联系方式：164981";
  document.body.appendChild(detaildiv);
  document.getElementById("detail").style.display = "block";
  detaildiv.style.left = demo.getBoundingClientRect().left+135+"px";
  detaildiv.style.top = demo.getBoundingClientRect().top+"px";
  console.log(demo.currentStyle); console.log(demo.getBoundingClientRect().left);

}
function mouseout() {
    document.getElementById("detail").style.display = "none";
}
