using System.IO;
using System.Runtime.Serialization.Formatters.Binary;
using System.Text;
using Microsoft.VisualStudio.DebuggerVisualizers;
using Newtonsoft.Json;

namespace OpenCvSharp.DebuggerVisualizers
{
    /// <summary>
    /// シリアライズ処理
    /// </summary>
    public class MatObjectSource : VisualizerObjectSource
    {
        static JsonSerializer serializer = new JsonSerializer();

        public override void GetData(object target, Stream outgoingData)
        {
            var proxy = new MatProxy((Mat)target);
            // JsonConvert.SerializeObject(proxy.ImageData);

            using (StreamWriter sw = new StreamWriter(outgoingData))
            using (JsonWriter writer = new JsonTextWriter(sw))
            {
                serializer.Serialize(writer, proxy.ImageData);
            }

            //var json = JsonConvert.SerializeObject(new MatProxy((Mat)target));
            //var bytes=Encoding.ASCII.GetBytes(json);
            //outgoingData.Write(bytes,0, bytes.Length);
            // bf.Serialize(outgoingData, new MatProxy((Mat)target));
        }
    }
}
