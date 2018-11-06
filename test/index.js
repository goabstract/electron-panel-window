var nativeExtension = require('../');
var assert = require('assert');

describe('native extension', function() {
  it('should export a function that returns a boolean', function() {
    assert.equal(typeof nativeExtension.MakePanel(), 'boolean');
  });
});
