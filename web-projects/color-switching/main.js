var select = document.querySelector('select');
var html = document.querySelector('.output');

select.onchange = function() {
  var choice = select.value;

  // ADD SWITCH STATEMENT
  let bgColor = "";
  let textColor = "black";
  switch(choice) {
    case "white":
        bgColor = "white";
	break;
    case "black":
	bgColor = "black";
	textColor = "white";
	break;
    case "purple":
	bgColor = "purple";
	textColor = "white";
	break;
    case "yellow":
	bgColor = "yellow";
	break;
    case "psychedelic":
	bgColor = "lime";
	break;
    default:
        bgColor = "white";
  }
  update(bgColor, textColor);
}

function update(bgColor, textColor) {
  html.style.backgroundColor = bgColor;
  html.style.color = textColor;
}