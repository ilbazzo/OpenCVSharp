using System.Diagnostics;
using System.Reflection;
using System.Runtime.InteropServices;


// OpenCvSharp objects' debugger visualizer
[assembly: DebuggerVisualizer(
    typeof(OpenCvSharp.DebuggerVisualizers.MatDebuggerVisualizer),
    typeof(OpenCvSharp.DebuggerVisualizers.MatObjectSource),
    Target = typeof(OpenCvSharp.Mat),
    Description = "Mat Visualizer"
)]
