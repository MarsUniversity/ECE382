
const punycode = require('punycode');
var fs = require('fs');
var path = require('path');
var childProcess = require('child_process');
var execSync = childProcess.execSync;

var w = execSync('which pandoc').toString();

if (typeof(w) !== 'string'){
  throw 'Is pandoc installed?';
}
var pandocPath = w.substr(0, w.length - 1);

exports.cleanAscii = function(file){
  // get markdown
  var text;
  try {
    text = fs.readFileSync(file, 'ascii');
    res = punycode.toASCII(text);
    fs.writeFileSync(file, res, {encoding: 'ascii'});
  }
  catch (err) {
    console.log(err);
    throw err;
  }
}


exports.convertMarkdown = function(input, output_type, args, callback) {
  // console.log('DEBUG: ' + input);
  // cleanAscii(input);

  var cmd;
  switch (output_type) {
    case 'html':
      cmd = pandocPath + ' -f markdown -t html5 ' + input;
    case 'pdf':
      cmd = pandocPath + ' -V geometry:margin=1in -s -o ' + path.basename(input, '.md') + '.pdf ' + input;
  }

  // console.log('DEBUG: ' + cmd);

  try {
    var ret = execSync(cmd).toString();
    // console.log(ret);
    callback(null, ret);
  }
  catch(err) {
    console.log('PANDOC ERROR: ', err);
    callback(err, null);
  }
};

exports.convertMarkdown2 = function(input, output_type) {
  // console.log('DEBUG: ' + input);
  // cleanAscii(input);

  // find out if args was passed to function
  // if (typeof(args) === 'undefined'){
  //   console.log('no optional args passed');
  //   args = args || ' ';  // need better
  // }

  var cmd;
  switch (output_type) {
    case 'html':
      cmd = pandocPath + ' -f markdown -t html5 ' + input;
      break;
    case 'pdf':
      cmd = pandocPath + ' -V geometry:margin=1in -s -o ' + path.basename(input, '.md') + '.pdf ' + input;
      break;
  }

  // console.log('DEBUG: ' + cmd);

  try {
    var ret = execSync(cmd).toString();
    // console.log(ret);
    return ret;
  }
  catch(err) {
    console.log('PANDOC ERROR: ', err);
    throw err;
  }
};
