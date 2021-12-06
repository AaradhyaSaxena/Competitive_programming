// Create Emitter

// The createEmitter function should create a new EventEmitter and register "open" and "close" event listeners. 
// The callbacks for those events should be onOpen and onClose arguments, respectively. 
// The opened and closed methods should raise "open" and "close" events on the EventEmitter they will receive as emitter arguments.
// The callbacks should only be invoked once per emitter.

// For example, after executing the following code, it should print "Opened!" and then "Closed!":
/*	let emitter = createEmitter(
		() => console.log("Opened!"), () => console.log("Closed!")
	);
	opened(emitter);
	closed(emitter);  */
//////

const events = require("events");
const myEmitter = new events.EventEmitter();

function createEmitter(onOpen, onClose) {    
	myEmitter.once('open', onOpen); 
	myEmitter.once('close', onClose);
	return myEmitter;
}

function opened(emitter) {
	myEmitter.emit('open', emitter); 
}
function closed(emitter) {
	myEmitter.emit('close', emitter);
}

let emitter = createEmitter(
	() => console.log("Opened!"), () => console.log("Closed!")
);
opened(emitter);
closed(emitter);

module.exports.createEmitter = createEmitter;
module.exports.opened = opened;
module.exports.closed = closed;
/////////////////////////////////////////////////////////

// Get in Parallel
// Implement the getInParallel function that should be used to invoke multiple API calls in parallel. 
// The function accepts an array of functions that return a Promise. 
// The function should return a Promise which should resolve to an array of results from the apiCalls argument.
// For example, calling the following code should print "[ 'First API call!', 'Second API call!' ]":
/*  
	let promise = getInParallel([() => Promise.resolve("First API call!"),
								() => Promise.resolve("Second API call!")]);
	if(promise) {
		promise.then((result) => console.log(result))
			   .catch((err) => console.log(err));
	}  
*/

function getInParallel(apiCalls) {
	let functions = apiCalls.map(apiCall => apiCall());
	return Promise.all(functions).then(response => response);
}

let promise = getInParallel(
			[() => Promise.resolve("First API call!"),
			 () => Promise.resolve("Second API call!")]);
if(promise) {
	promise.then((result) => console.log(result))
		   .catch((err) => console.log(err));
}
module.exports.getInParallel = getInParallel;
/////////////////////////////////////////////

// First Promise
// A company uses a Node.js application that checks several data sources for requested information. 
// Since each request to a data source is performance heavy, the application should try to check the next source only 
// if the request failed at the current data source. That functionality was extracted into the firstSuccessfulPromise function.

// The firstSuccessfulPromise function accepts an array of Promises as a promiseArray parameter. 
// The function should return a Promise which should resolve to the first successful result from the promiseArray.

// If no Promise from the promiseArray returns successfully, the function should return undefined.
// For example, if the following code is executed:
/*
	firstSuccessfulPromise([new Promise((resolve, reject) => reject()), 
				new Promise((resolve, reject) => resolve("Success!"))])
	.then(result => console.log(result));
*/
// It should print "Success!".

async function firstSuccessfulPromise(promiseArray) {
	// Write your code here
}

let promise = firstSuccessfulPromise([new Promise((resolve, reject) => reject()), 
			new Promise((resolve, reject) => resolve("Success!"))]);
promise.then(result => console.log(result));

module.exports.firstSuccessfulPromise = firstSuccessfulPromise;
























