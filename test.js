//var cpupower = require('./build/Release/cpupower');
//var cpupower = require('bindings')('cpupower');
var cpupower = require('../cpupower');

var data = new Buffer("7000000001e980924e4e1109230383e66d62945ff8e749903bea4336755c00000000000051928aff1b4d72416173a8c3948159a09a73ac3bb556aa6bfbcad1a85da7f4c1d13350531e24031b939b9e2b", "hex");
console.log(cpupower.hash(data).toString('hex'));
// result: 91aed7746ff09fa6b475c5da2672f0150508c2b90bc999a8400047feeb5b9c1e
