using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using System.Windows.Forms;
using OpenCvSharp;

namespace OpenCvSharp.DebuggerVisualizers.Tester
{
	static class Program
	{
		/// <summary>
		/// 应用程序的主入口点。
		/// </summary>
		[STAThread]
		static void Main()
		{
			Application.EnableVisualStyles();
			Application.SetCompatibleTextRenderingDefault(false);

			var img = new OpenCvSharp.Mat(@"_data\image\calibration\00.jpg");
            var src = new MatProxy(img);

            using (var proxy = new MatProxy(objectProvider3.GetData()))
            {
                if (proxy is null)
                {
                    throw new ArgumentException();
                }
                // Formに表示
                using (var form = new ImageViewer(proxy))
                {
                    Application.Run(form);
                    // windowService.ShowDialog(form);
                }
            }

   //         var mainForm = new ImageViewer(img);
			//Application.Run(mainForm);
		}
	}
}
