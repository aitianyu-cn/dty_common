using System;
namespace DTY.Dotnet.Tools.Common.Json
{
	/// <summary>
    /// Json Writing Params object is used to provoide some configures for serializing the json entity
    /// </summary>
	public class JsonWritingParams
	{
		/// <summary>
        /// get or set a boolean value indicates the start brance of object type value should turn to new line.
        /// </summary>
		public bool IsPreBranceNewLine { get; set; } = true;
		/// <summary>
		/// get or set a boolean value indicates the end brance of object type value should turn to new line.
		/// </summary>
		public bool IsEndBranceNewLine { get; set; } = true;
		/// <summary>
        /// get or set a boolean value indicates the prefix is blank space or a tab.
        /// </summary>
		public bool IsBlankSpace { get; set; } = true;
		/// <summary>
        /// get or set a int value indicates the count of the prefix blank space.
        /// this value has no sense if the IsBlankSpace flag is false.
        /// </summary>
		public int BlankSpaceCount { get; set; } = 4;
		/// <summary>
        /// get or set a int value indicates the count of the prefix blank space before end brance.
        /// </summary>
		public int BlankSpaceBeforeEndBrance { get; set; } = 1;
		/// <summary>
		/// get or set a int value indicates the count of the blank space after start brance.
		/// </summary>
		public int BlankSpaceAfterPreBrance { get; set; } = 1;
		/// <summary>
        /// get or set a int value indicates the count of the blank space after colon.
        /// </summary>
		public int BlankSpaceAfterColon { get; set; } = 1;
		/// <summary>
        /// get or set a boolean value indicates the ending formatter of a line.
        /// </summary>
		public bool IsCRLFEnd { get; set; } = false;

		internal int HierarchyLevel { get; set; } = 0;
	}
}

