var app = require('electron').app;
var PanelWindow = require('../../').PanelWindow;
var path = require('path')

var mainWindow = null;

app.on('ready', function () {
  mainWindow = new PanelWindow({
    center: true,
    width: 1400,
    height: 900,
    minHeight: 100,
    minWidth: 100,
    show: false
  });
  mainWindow.loadURL('file://' + __dirname + '/index.html')
  mainWindow.on('closed', function () { mainWindow = null })
  mainWindow.on('ready-to-show',function() {
    mainWindow.show();
  });
})