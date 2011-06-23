var fs = require('fs');

var FILE = process.argv[2];

if(!FILE || typeof FILE !== 'string' || FILE.length <= 0) {
  throw 'Unexpected file name input!';
}

fs.writeFile(FILE, 'All your files are belong to us\n', 'utf8', function(err) {
  if(err) {
    console.log(err);
  }
});
