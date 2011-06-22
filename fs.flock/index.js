var fs = require('fs');

var FILE = './balance';
var FILE_ENCODING = 'utf8';

fs.readFile(FILE, FILE_ENCODING, function(err, data) {
  console.log(process.pid, 'Have', data);

  var toWrite;

  if(!data) {
    toWrite = 2;
    console.log(process.pid, 'Writing', toWrite);
  }
  else if(process.argv[2] % 2 === 0) {
    toWrite = String(Number(data) - 1);
    console.log(process.pid, 'Writing (-1)', toWrite);
  }
  else {
    toWrite = String(Number(data) * 2);
    console.log(process.pid, 'Writing (*2)', toWrite);
  }

  fs.writeFile(FILE, toWrite + '\n', FILE_ENCODING, function(err) {
    if(err) {
      console.log(process.pid, 'ERROR', err);
    }
    else {
      console.log(process.pid, 'Done Writing');
    }
  });
});
