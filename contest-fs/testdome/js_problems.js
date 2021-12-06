// Remove Property
// Implement the removeProperty function which takes an object and property name, and does the following:
// If the object obj has a property prop, the function removes the property from the object and returns true; 
// in all other cases it returns false.

function removeProperty(obj, prop) {
	if(prop in obj){
	  delete obj[prop]
	  return true;
	}
	else{
	  return false;
	}
}
//////////////////////////////////////////////

// 2 sum
// Write a function that, when passed an array and a target sum, returns, efficiently with respect to time used, 
// two distinct zero-based indices of any two of the numbers, whose sum is equal to the target sum. 
// If there are no two numbers, the function should return null.

function findTwoSum(numbers, sum) {
	var mp = new Map();
	for(var i=0; i<numbers.length; i++){
	  if(mp[sum-numbers[i]]){
		return [mp[sum-numbers[i]], i];
	  }
	  if(!mp[numbers[i]]){
		mp[numbers[i]] = i;
	  }
	}
	return null;
}

const indices = findTwoSum([ 3, 1, 5, 7, 5, 9 ], 10);
console.log(indices);
//////////////////////////////////////////////

// Date
// Write a function that converts user entered date formatted as M/D/YYYY to a format required by an API (YYYYMMDD). 
// The parameter "userDate" and the return value are strings.
// For example, it should convert user entered date "12/31/2014" to "2014123

function formatDate(userDate) {
	// format from M/D/YYYY to YYYYMMDD
	const x = userDate.split('/');
	if(x[0].length === 1){ // to handle 1 digit month
	  x[0] = 0 + x[0];
	}
	if(x[1].length === 1){ // to handle 1 digit date
	  x[1] = 0 + x[1];
	}
	return `${x[2]}${x[0]}${x[1]}`;
  }
  
  console.log(formatDate("12/31/2014"));
//////////////////////////////////////////////

// Check Digit
// The check digit should be calculated by adding up all digits in each membership ID. 
// If the result of the sum is a number with more than a single digit, another iteration is required, 
// and the digits of the result also should be added together. 
// This process should repeat until a single-digit number is calculated.

function createCheckDigit(membershipId) {
	let sumMembershipId = aggregator(membershipId);
	while (parseInt(sumMembershipId) > 9) sumMembershipId = aggregator(sumMembershipId);
	return sumMembershipId;
}
function aggregator(strMembershipId) {
	return strMembershipId.toString().split('').reduce((a, b) => parseInt(a) + parseInt(b), 0);
}
console.log(createCheckDigit("55555"));
//////////////////////////////////////////////

// Ensure
// Implement the ensure function so that it throws an error if called without arguments or the argument is undefined. 
// Otherwise it should return the given value.

function ensure(value) {
	if(value !== undefined){
	  return value;
	}
	throw Error;
}
try {
	console.log(ensure());
	} catch(err) {
	console.log(err);
}
//////////////////////////////////////////////

// Songs
// A playlist is considered a repeating playlist if any of the songs contain a reference to a previous song in the playlist. 
// Otherwise, the playlist will end with the last song which points to undefined.
// Implement the method isRepeatingPlaylist that, efficiently with respect to time used, 
// returns true if a playlist is repeating or false if it is not

class Song {
	name;
	nextSong;
	constructor(name) {
	  this.name = name;
	}
	isRepeatingPlaylist() {
	  var inqueue = {};
	  while(this.nextSong){
		if(inqueue[this.name]!=null){
		  return true;
		}
		else{
		  inqueue[this.name] = 1;
		  this.name = this.nextSong.name;
		  this.nextSong = this.nextSong.nextSong;
		}
	  }
	  return false;
	}
}

let first = new Song("Hello");
let second = new Song("Eye of the tiger");
first.nextSong = second;
second.nextSong = first;
console.log(first.isRepeatingPlaylist());
//////////////////////////////////////////////

// Even Numbers
// A Mathematics tutoring web application for kids has a button that highlights all even numbers (in span), 
// using 'yellow' as the background color. Clicking the button again removes the background. 
// All further clicks add or remove the 'yellow' background alternately.

<div id='numbers'>
 <span>1</span><span>2</span><span>3</span><span>4</span><span>5</span>
 <button id='btn' onclick='toggleEvenColor()'>Toggle even number highlighting</button>
</div>

function toggleEvenColor() {
	let spanElements = document.querySelectorAll('#numbers span:nth-child(2n)');
	spanElements.forEach(function() {
		item.style.backgroundColor = item.style.backgroundColor !== 'yellow' ? 'yellow' : 'transparent';
	});
}
//////////////////////////////////////////////

// Closures
// Fix the bugs in the registerHandlers function. 
// An alert should display anchor's zero-based index within a document instead of following the link.
// For example, in the document below, the alert should display "2" when Google anchor is clicked since 
// it is the third anchor element in the document and its zero-based index is 2.
<body>
  In my life, I used the following web search engines:<br/>
  <a href="//www.yahoo.com">Yahoo!</a><br/>
  <a href="//www.altavista.com">AltaVista</a><br/>
  <a href="//www.google.com">Google</a><br/>
</body>

function registerHandlers() {
	var as = document.getElementsByTagName('a');
	for (var i = 0; i < as.length; i++) {
	  as[i].onclick = function(i) {
		return function() {
		  alert(i);
		  return false;
		}
	  }(i);
	}
  }
//////////////////////////////////////////////

// Wrapper
// Write a wrap function that takes the execute function as an argument and 
// returns a modified function so that the following requirements are met:
// Any result returned by the function execute should be returned from the modified function unchanged.
// If the function execute throws an error, the modified function should return null.
// After the function execute has thrown an error, its future executions should be prevented and null should be returned.
// Multiple wrapped functions can coexist.
// The execute function doesn't take any arguments.

function wrap (execute) {
	// Return modified function
}
var errorExec = wrap(function () {
	throw new Error('Error');
});
var resultExec = wrap(function () {
	return "Result";
});
console.log(errorExec && errorExec()); // Should output null
console.log(errorExec && resultExec()); // Should output "Result"

// Solution::
function wrap (execute) {
    let did_fail = false;
    
    return function() { 
        if (did_fail) {
            return null;
        }

        try {
            return execute(); 
        } catch {
            did_fail = true;
            return null;
        }
    }
}

// This works as well, so just a question, why is the return stuff wrapped in a function?logically, it would seem
function wrap (execute) {
    let did_failed = false;
    if (did_failed) {
        return null;
    }
    try {
        return execute();
    } catch (e) {
        did_failed = true;return null;
    }
}
// would be functional, but I also recognize that the 'global' variable 'did_failed' would probably be effected by this.

////////////////////////////////////////////////
////////////////////////////////////////////////////////



























