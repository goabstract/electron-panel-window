# electron-panel

Enables creating a browser window in Electron that behaves like an NSPanel.

## Usage

Use PanelWindow as you would [BrowserWindow](https://electronjs.org/docs/api/browser-window).

```javascript
import { PanelWindow } from 'electron-panel';

const win = new PanelWindow({
  width: 800,
  height: 600,
  show: false
})

// the window will show without activating the application
win.show();
```

You can also access the utility methods directly:

```javascript
import { remote } from 'electron';
import { makePanel, makeKeyWindow } from 'electron-panel';

const currentWindow = remote.getCurrentWindow();

// convert the window to an NSPanel
makePanel(currentWindow);

// focus the window without activating the application
makeKeyWindow(currentWindow);
```

## Building

To compile the extension for the first time, run 

```
$ yarn
$ yarn configure
$ yarn build
```

All subsequent builds only need `yarn build`

## The Parts

File | Contents
-------------|----------------
`NativeExtension.cc` | Represents the top level of the module. C++ constructs that are exposed to javascript are exported here
`functions.cc` | The meat of the extension
`index.js` | The main entry point for the node dependency
`binding.gyp` | Describes the node native extension to the build system (`node-gyp`). If you add source files to the project, you should also add them to the binding file.

## License

This project is under MIT.
See [LICENSE](https://github.com/goabstract/electron-panel/blob/master/LICENSE)

