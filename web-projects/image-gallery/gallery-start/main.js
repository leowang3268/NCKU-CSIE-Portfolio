const displayedImage = document.querySelector('.displayed-img');
const thumbBar = document.querySelector('.thumb-bar');

const btn = document.querySelector('button');
const overlay = document.querySelector('.overlay');


function chooseImage(e) {
    displayedImage.setAttribute('src', e.target.getAttribute('src'));
}

/* Looping through images */

for (let i=1; i<6; i++ ) {
    const newImage = document.createElement('img');
    newImage.setAttribute('src', 'images/pic'+i.toString()+'.jpg');
    thumbBar.appendChild(newImage);
    newImage.addEventListener('click', chooseImage);
}


/* Wiring up the Darken/Lighten button */

function darkenAndLighten(e) {
    let status = btn.getAttribute('class');
    if (status === 'dark') {
        btn.setAttribute('class', 'light');
        btn.textContent = 'Lighten';
        overlay.style.backgroundColor =  'rgba(0,0,0,0.5)';
    }
    else {
        btn.setAttribute('class', 'dark');
        btn.textContent = 'Darken';
        overlay.style.backgroundColor =  'rgba(0,0,0,0)';
    }
}

btn.addEventListener('click', darkenAndLighten);