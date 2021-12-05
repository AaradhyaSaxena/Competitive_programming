// An image gallery
// An image gallery is a set of images with corresponding remove buttons. 
// Implement the setup function that registers a click event handler and implements the following logic: 
// When the button of class remove is clicked, its parent <div> element should be removed from the gallery.

function setup() {
    var els = document.getElementsByClassName("remove");
    for (var i = 0; i < els.length; i++) {
        els[i].addEventListener('click', function (e) {
            e.preventDefault();
            e.target.closest('div.image').remove();
        });
    }
}

// Example case. 
document.body.innerHTML = `
<div class="image">
  <img src="https://bit.ly/3lmYVna" alt="First">
  <button class="remove">X</button>
</div>
<div class="image">
  <img src="https://bit.ly/3flyaMj" alt="Second">
  <button class="remove">X</button>
</div>`;

setup();

document.getElementsByClassName("remove")[0].click();
console.log(document.body.innerHTML);
//////////////////////////////////////////////

// Topic-Coloring
// Write the function newMessage, which receives the name of the topic as the parameter. 
// Function should change the background color of the p tag to red where the data-topic-name is topicName. 
// A topicName that doesn't have a matching data-topic-name should be ignored.

function newMessage(topicName) {
  var ele = document.querySelector('p[data-topic-name='+topicName+']');
  if(ele){
    ele.style.backgroundColor = "red";
  }
}

// Example case
document.body.innerHTML = `<div>
  <p data-topic-name="discussion">General discussion</p>
  <p data-topic-name="bugs">Bugs</p>
  <p data-topic-name="animals">Animals</p>
</div>`;
newMessage("bugss");
console.log(document.body.innerHTML);
//////////////////////////////////////////////

// Closest Relative
// Implement the closestRelative function so that when a parent HTML element is passed, 
// the function returns the parent's closest relative whose name matches the relativeName, and obeys the following rules:

function closestRelative(parent, relativeName) {
  // BFS
  firstLevel = document.getElementsByTagName(parent);
  if (firstLevel.length) {
    result = document.getElementsByTagName(firstLevel).filter(relativeName);
    
    if (result.length) {
      return result.first();
    } else {
      return closestRelative(firstLevel, relativeName);
    }
  } 
  else {
    return $([]);
  }
}

// Example case
document.body.innerHTML = 
'<James>' +
  '<Dave></Dave>' +
  '<Mike></Mike>' +
  '<Sarah></Sarah>' +
'</James>';

let parent = document.getElementsByTagName('James')[0];
let relative = closestRelative(parent, 'Mike');
console.log(relative && relative.tagName); // prints MIKE
//////////////////////////////////////////////

//  Endangered Species
// An HTML div element contains lists of endangered species grouped by continent and the species population status.
<div>
    <ul data-continent="North America">
        <li data-species="California condor">Critically Endangered</li>
        <li data-species="American bison">Near Threatened</li>
    </ul>
    <ul data-continent="Europe">
        <li data-species="Cave bear">Extinct</li>
    </ul>
</div>
// Implement the function endangeredSpecies that returns how endangered a species is on a particular continent.
// For example, endangeredSpecies('North America', 'American bison') should return 'Near Threatened'.

function endangeredSpecies(continent, species) {
  var res = document.querySelectorAll(`[data-continent="${continent}"] [data-species="${species}"]` );
  return res[0].textContent;
}

// Example case
document.body.innerHTML =
`<div>
  <ul data-continent="North America">
    <li data-species="California condor">Critically Endangered</li>
    <li data-species="American bison">Near Threatened</li>
  </ul>
  <ul data-continent="Europe">
    <li data-species="Cave bear">Extinct</li>
  </ul>
</div>`;

console.log(endangeredSpecies('North America', 'American bison')); // should print 'Near Threatened'
//////////////////////////////////////////////

// Food Ranking
// A website needs a list where users can rank their favorite foods. Write the setup function, 
// which should register click handlers on all Up! and Down! buttons. 
// The Up! button should move the list item one place up in the list, 
// while Down! button should move the list item one place down in the list.

<ol>
  <li><button class="up">Up!</button>Taco<button class="down">Down!</button> </li>
  <li><button class="up">Up!</button>Pizza<button class="down">Down!</button></li>
  <li><button class="up">Up!</button>Eggs<button class="down">Down!</button></li>
</ol>


$.fn.moveUp = function() {
  before = $(this).prev();
  $(this).insertBefore(before)
}

$.fn.moveDown = function() {
  after=$(this).next();
  $(this).insertAfter(after)
}

$('.up').click(function() {
  $(this).parent().moveUp()
})

$('.down').click(function() {
  $(this).parent().moveDown()
})
//////////////////////////////////////////////

// Loop
// Function appendChildren should add a new child div to each existing div. New divs should be decorated by calling decorateDiv.
// For example, after appendChildren is executed, the following divs:
<div id="a">
  <div id="b">
  </div>
</div>
// should take the following form (assuming decorateDiv does nothing):
<div id="a">
  <div id="b">
    <div></div>
  </div>
  <div></div>
</div>
// The code below should do the job, but for some reason it goes into an infinite loop. Fix the bugs.
function appendChildren(decorateDiv) {

  //var allDivs = document.getElementsByTagName("div"); //bug
  var allDivs = [ ...document.getElementsByTagName("div")];

  for (var i = 0; i < allDivs.length; i++) {
    var newDiv = document.createElement("div");
    decorateDiv(newDiv);
    allDivs[i].appendChild(newDiv);
  }
}
//////////////////////////////////////////////


















