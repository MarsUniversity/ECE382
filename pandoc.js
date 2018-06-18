
const punycode = require('punycode');
var fs = require('fs');
var path = require('path');
var childProcess = require('child_process');
var execSync = childProcess.execSync;
// const { execsync } = require('child_process');

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


// exports.convertMarkdown = function(input, output_type, args, callback) {
//   // console.log('DEBUG: ' + input);
//   // cleanAscii(input);
//
//   var cmd;
//   switch (output_type) {
//     case 'html':
//       cmd = pandocPath + ' -f markdown -t html5 ' + input;
//     case 'pdf':
//       cmd = pandocPath + ' -V geometry:margin=1in -s -o ' + path.basename(input, '.md') + '.pdf ' + input;
//   }
//
//   // console.log('DEBUG: ' + cmd);
//
//   try {
//     var ret = execSync(cmd).toString();
//     // console.log(ret);
//     callback(null, ret);
//   }
//   catch(err) {
//     console.log('PANDOC ERROR: ', err);
//     callback(err, null);
//   }
// };
//
// exports.convertMarkdown2 = function(input, output_type) {
//   // console.log('DEBUG: ' + input);
//   // cleanAscii(input);
//
//   // find out if args was passed to function
//   // if (typeof(args) === 'undefined'){
//   //   console.log('no optional args passed');
//   //   args = args || ' ';  // need better
//   // }
//
//   var cmd;
//   switch (output_type) {
//     case 'html':
//       cmd = pandocPath + ' -f markdown -t html5 ' + input;
//       break;
//     case 'pdf':
//       cmd = pandocPath + ' -V geometry:margin=1in -s -o ' + path.basename(input, '.md') + '.pdf ' + input;
//       break;
//   }
//
//   // console.log('DEBUG: ' + cmd);
//
//   try {
//     var ret = execSync(cmd).toString();
//     // console.log(ret);
//     return ret;
//   }
//   catch(err) {
//     console.log('PANDOC ERROR: ', err);
//     throw err;
//   }
// };

exports.convertToHTML = function(inFile) {

  var output_type;
  switch(path.extname(inFile)){
    case ".md":
      output_type = 'markdown';
      break;
    case ".rst":
      output_type = 'rst';
      break;
    default:
      throw "convertHTML: unknown file extention, must be md or rst";
  }

  // console.log('try: ' + execSync('pandoc -f markdown -t html5-smart source/admin/final_resources/final.md').toString());
  // console.log(execSync('pwd').toString());
  // console.log(execSync('ls').toString());

  // add --quiet to surpress warnings
  var cmd = pandocPath + ' -f ' + output_type + ' -t html5-smart ' + inFile;

  try {
    // console.log(cmd);
    // console.log('------------------------------------------------')
    // var opts = {
    //   timeout: 5000,
    //   killSignal: 'SIGKILL'
    // };
    // return execSync(cmd, opts).toString();
    // return exec(cmd).toString();
    // var ret = exec(cmd).stdout.toString();

//     const {execSync} = require('child_process');
//     go = execSync(cmd);
//     go.stdout.on( 'data', data => {
//       console.log(`wtf ${data}`);
//     });
//     go.stderr.on( 'data', data => {
//     console.log( `stderr: ${data}` );
// } );
//
// go.on( 'close', code => {
//     console.log( `child process exited with code ${code}` );
// } );
    // console.log(ret);
    // console.log(ret);
    // return ret;
  }
  catch(err) {
    // console.log("std: " + err.stdout.toString());
    // console.log("err: " + err.stderr.toString());
    // console.log(err.pid);
    // console.log(err.signal);
    // console.log(err.status);
    console.log('PANDOC ERROR: ', err);
    throw err;
  }
};
