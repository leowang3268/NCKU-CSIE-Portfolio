var list = document.querySelector('.output ul');
var totalBox = document.querySelector('.output p');
var total = 0;
list.innerHTML = '';
totalBox.textContent = '';
// number 1
let data = "Underpants:6.99 Socks:5.99 T-shirt:14.99 Trousers:31.99 Shoes:23.99";
let product = data.split(' ');
let product_name = [];
let product_price = [];
for (var i = 0; i < product.length; i++) { // number 2
  // number 3
  product_name[i] = product[i].slice(0,product[i].indexOf(':'));
  product_price[i] = Number(product[i].slice(product[i].indexOf(':')+1));
  // number 4
  total += product_price[i];
  // number 5
  itemText = "";
  itemText = `${product_name[i]}—\$${product_price[i]}`;
  var listItem = document.createElement('li');
  listItem.textContent = itemText;
  list.appendChild(listItem);
}

totalBox.textContent = 'Total: $' + total.toFixed(2);
