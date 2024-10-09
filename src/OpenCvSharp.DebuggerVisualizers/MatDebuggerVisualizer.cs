using System;
using Microsoft.VisualStudio.DebuggerVisualizers;

namespace OpenCvSharp.DebuggerVisualizers
{
    /// <summary>
    /// ビジュアライザでの視覚化処理
    /// </summary>
    public class MatDebuggerVisualizer : DialogDebuggerVisualizer
    {
        public MatDebuggerVisualizer() : base(FormatterPolicy.NewtonsoftJson)
        { 
        }

        protected override void Show(IDialogVisualizerService windowService, IVisualizerObjectProvider objectProvider)
        {
            IVisualizerObjectProvider3 objectProvider3 = objectProvider as IVisualizerObjectProvider3;
            using (var proxy = new MatProxy(objectProvider3.GetData()))
            {
                if (proxy is null)
                {
                    throw new ArgumentException();
                }
                // Formに表示
                using (var form = new ImageViewer(proxy))
                {
                    windowService.ShowDialog(form);
                }
            } 
        }
    }
}
