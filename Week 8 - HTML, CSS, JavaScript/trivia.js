            document.addEventListener('DOMContentLoaded', function() {
              // Part 1 code
              let correct = document.querySelector('.correct');
              correct.addEventListener('click', function() {
                correct.style.backgroundColor = 'green';
                document.querySelector('#feedback1').innerHTML = ('Correct!');
              });

              let incorrects = document.querySelectorAll('.incorrect');
              for (let i = 0; i < incorrects.length; i++) {
                incorrects[i].addEventListener('click', function() {
                  incorrects[i].style.backgroundColor = 'red';
                  document.querySelector('#feedback1').innerHTML = 'Incorrect';
                });
              }

              // Part 2 code
              const checkButton = document.getElementById('check');
              checkButton.addEventListener('click', function() {
                const answer = document.querySelector('input[type=text]').value.toLowerCase();
                if (answer === 'mount everest' || answer === 'everest') {
                  document.querySelector('#feedback2').innerHTML = 'Correct!';
                  document.querySelector('input[type=text]').style.backgroundColor = 'green';
                } else {
                  document.querySelector('#feedback2').innerHTML = 'Incorrect';
                  document.querySelector('input[type=text]').style.backgroundColor = 'red';
                }
              });

              // Add listener for enter key press
              document.addEventListener('keydown', function(event) {
                if (event.key === 'Enter') {
                  const answer = document.querySelector('input[type=text]').value.toLowerCase();
                  if (answer === 'mount everest' || answer === 'everest') {
                    document.querySelector('#feedback2').innerHTML = 'Correct!';
                    document.querySelector('input[type=text]').style.backgroundColor = 'green';
                  } else {
                    document.querySelector('#feedback2').innerHTML = 'Incorrect';
                    document.querySelector('input[type=text]').style.backgroundColor = 'red';
                  }
                }
              });
            });
