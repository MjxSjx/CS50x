const inputBox = document.getElementById('input-box');
const submitBtn = document.getElementById('submit-btn');

submitBtn.addEventListener('click', processInput);

inputBox.addEventListener('keydown', function(event) {
  if (event.key === 'Enter') {
    event.preventDefault();
    processInput();
  }
});

function processInput() {
  const message = inputBox.value;
  inputBox.value = '';

  const div = document.createElement('div');
  div.innerText = message.split('').reverse().join('');
  div.style.color = getRandomColor();
  div.style.position = 'absolute';
  div.style.left = `${getRandomNumber(window.innerWidth - 100)}px`;
  div.style.top = `${getRandomNumber(window.innerHeight - 100)}px`;
  div.style.fontSize = '66px';
  document.body.appendChild(div);

  setTimeout(() => {
    div.style.opacity = 0;
    setTimeout(() => {
      div.remove();
    }, 1000);
  }, 4000);
}

function getRandomNumber(max) {
  return Math.floor(Math.random() * max);
}

function getRandomColor() {
  const r = getRandomNumber(256);
  const g = getRandomNumber(256);
  const b = getRandomNumber(256);
  return `rgb(${r},${g},${b})`;
}
