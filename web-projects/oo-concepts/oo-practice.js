
let bandInfo;

// Put your code here
let band = {
    name: 'Queen',
    nationality: 'UK',
    genre: 'rock',
    members: 4,
    formed: 1970,
    split: false,
    albums: [
        {
            name:'A Night at the Opera',
            released: 1975
        },
        {
            name: 'News of the World',
            released: 1977
        }
    ]
};

bandInfo = `${band.name} is my favorite band. It is from ${band.nationality}, and it's a ${band.genre} band. 
There were ${band.members} in the band, and it was formed in ${band.formed}.`;
if (band.split === false) {
    bandInfo += ' The band has not splitted.'
}
else {
    bandInfo += ` The band has splitted in ${band.split}.`
}
bandInfo += ' My favorite album of them are ';
for (let i=0; i<band.albums.length-1; i++) {
    bandInfo += `${band.albums[i].name} (released in ${band.albums[i].released}) and `
}
bandInfo += `${band.albums[band.albums.length-1].name} (released in ${band.albums[band.albums.length-1].released}).`

// Don't edit the code below here

let para1 = document.createElement('p');
para1.textContent = bandInfo;
section.appendChild(para1);