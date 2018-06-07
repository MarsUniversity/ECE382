#!/usr/bin/env node

var pandoc = require('./pandoc.js')
var fs = require('fs')
var path = require('path')
var ejs = require('ejs');


function readAsciiFile(file){
  // value of this?
  // get markdown
  var text;
  try {
    text = fs.readFileSync(mdFile, 'ascii');
    return text;
  }
  catch (err) {
    console.log(err);
    throw err;
  }
}

function convertMarkdown(mdFile, template, output) {

    var result = pandoc.convertMarkdown2(mdFile, 'html');
    var htmlFile = output + '/' + path.basename(mdFile, '.md') + '.html';
    console.log('Wrote: ' + htmlFile);
    // var html = template({info: result.html.toString()});
    var html = template({info: result, path: __dirname + '/html'});
    fs.writeFileSync(htmlFile, html);

}

function recursiveSearch(directory, template, output){
  console.log('-------------------------------------------')
  console.log('Searching: ' + directory);

  // get files
  var files;
  try {
    files = fs.readdirSync(directory);
  }
  catch (err) {
    console.log(err);
  }

  for (var i = 0; i < files.length; i++) {
      var currentFile = directory + '/' + files[i];

      switch (path.extname(files[i])) {
          case '.md':
              convertMarkdown(currentFile, template, output);
              break;
          case '':
              if (fs.statSync(currentFile).isDirectory() == true){
                fs.mkdirSync(output + '/' + files[i]);
                recursiveSearch(currentFile, template, output + '/' + files[i]);
              }

              break;
          default:
              // copy to output directory
              var cp = output + '/' + files[i];
              fs.copyFileSync(currentFile, cp);
              console.log('Copied: ' + cp);
              break;
      }
  }
}

function build(templateFile, directory, output){
  // delete old build and recreate it so we always have a clean build
  // fs.rmdirSync(output);
  var execSync = require('child_process').execSync;
  execSync('rm -rf ' + output);

  fs.mkdirSync(output);

  // get template
  var ejs_string = fs.readFileSync(templateFile, 'utf8');
  var template = ejs.compile(ejs_string);

  // search through source and build html
  recursiveSearch(directory, template, output);

}

build('template.ejs', 'source', 'html');
