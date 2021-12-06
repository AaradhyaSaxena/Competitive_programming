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

// test mistake
// What will log to console the following code snippet:
function createIncrement() {
  let count = 0;
  function increment() { 
    count++;
  }
  let message = `Count is ${count}`;
  function log() {
    console.log(message);
  }
  
  return [increment, log];
}
const [increment, log] = createIncrement();
increment(); 
increment(); 
increment(); 
log(); // What is logged?

/*
'Count is 0' is logged to console. 
increment() function has been called 3 times, effectively incrementing count to value 3.

message variable exists within the scope of createIncrement() function. Its initial value is 'Count is 0'. 
However, even if count variable has been incremented a few times, message variable always holds 'Count is 0'.

log() function is a closure that captures message variable from the createIncrement() scope. 
console.log(message) logs 'Count is 0' to console.
*/
////////////////////////////////////////

//// Restore encapsulation
// The following function createStack() creates instances of stack data structure:

function createStack() {
  return {
    items: [],
    push(item) {
      this.items.push(item);
    },
    pop() {
      return this.items.pop();
    }
  };
}
const stack = createStack();
stack.push(10);
stack.push(5);
stack.pop(); // => 5
stack.items; // => [10]
stack.items = [10, 100, 1000]; // Encapsulation broken!

// The stack works as expected, but with one small problem. 
// Anyone can modify items array directly because stack.items property is exposed.

// That's an issue since it breaks the encapsulation of the stack: only push() and pop() methods should be public, 
// but stack.items or any other details shouldn't be accessible.

// Refactor the above stack implementation, using the concept of closure, 
// such that there is no way to access items array outside of createStack() function scope:

function createStack() {
	const items = [];
	return {
	  push(item) {
		items.push(item);
	  },
	  pop() {
		return items.pop();
	  }
	};
}
const stack = createStack();
stack.push(10);
stack.push(5);
stack.pop(); // => 5
stack.items; // => undefined

// items has been moved to a variable inside createStack() scope.

// Thanks to this change, from the outside of createStack() scope, there is no way to access or modify items array. 
// items is now a private variable, and the stack is encapsulated: only push() and pop() method are public.

// push() and pop() methods, being closures, capture items variable from createStack() function scope.
////////////////////////////////////////////////////////

//// Smart multiplication
// Write a function multiply() that multiples 2 numbers:

function multiply(num1, num2) {
  // Write your code here...
}

// If multiply(num1, numb2) is invoked with 2 arguments, it should return the multiplication of the 2 arguments.
// But if invoked with 1 argument const anotherFunc = multiply(num1), the function should return another function. 
// The returned function when called anotherFunc(num2) performs the multiplication num1 * num2.

multiply(4, 5); // => 20
multiply(3, 3); // => 9
const double = multiply(2);
double(5);  // => 10
double(11); // => 22

// Here's a possible implementation of multiply() function:

function multiply(number1, number2) {
  if (number2 !== undefined) {
    return number1 * number2;
  }
  return function doMultiply(number2) {
    return number1 * number2;
  };
}
multiply(4, 5); // => 20
multiply(3, 3); // => 9
const double = multiply(2);
double(5);  // => 10
double(11); // => 22

/////////////////////////////////










