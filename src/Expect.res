type chai

module Expect = {
  @module("chai") external expect: 'a => chai = "expect"
}

module Chains = {
  @get external to_: chai => chai = "to"
  @get external be: chai => chai = "be"
  @get external been: chai => chai = "been"
  @get external is: chai => chai = "is"
  @get external that: chai => chai = "that"
  @get external which: chai => chai = "which"
  @get external and_: chai => chai = "and"
  @get external has: chai => chai = "has"
  @get external have: chai => chai = "have"
  @get external with_: chai => chai = "with"
  @get external at: chai => chai = "at"
  @get external of_: chai => chai = "of"
  @get external same: chai => chai = "same"
  @get external but: chai => chai = "but"
  @get external does: chai => chai = "does"
}

module Modifiers = {
  @get external not: chai => chai = "not"
  @get external deep: chai => chai = "deep"
  @get external nested: chai => chai = "nested"
  @get external own: chai => chai = "own"
  @get external ordered: chai => chai = "ordered"
  @get external any: chai => chai = "any"
  @get external all: chai => chai = "all"
  @get external itself: chai => chai = "itself"
  @get external include_: chai => chai = "include"
}

module Comparisons = {
  module Internal = {
    type constructor
    @send
    external a: (chai, string, ~msg: string=?) => chai = "a"
    @send
    external include_: (chai, 'a, ~msg: string=?) => chai = "include"
    @send
    external equal: (chai, 'a, ~msg: string=?) => chai = "equal"
    @send
    external eql: (chai, Js.t<'a>, ~msg: string=?) => chai = "eql"
    @send
    external above: (chai, float, ~msg: string=?) => chai = "above"
    @send
    external below: (chai, float, ~msg: string=?) => chai = "below"
    @send
    external least: (chai, float, ~msg: string=?) => chai = "least"
    @send
    external most: (chai, float, ~msg: string=?) => chai = "most"
    @send
    external within: (chai, float, float, ~msg: string=?) => chai = "within"
    @send
    external instanceof: (chai, constructor, ~msg: string=?) => chai = "instanceof"
    @send
    external property: (chai, string, ~value: 'a=?, ~msg: string=?) => chai = "property"
    @send
    external ownPropertyDescriptor: (
      chai,
      string,
      ~descriptor: Js.t<'a>=?,
      ~msg: string=?,
    ) => chai = "ownPropertyDescriptor"
    @send
    external lengthOf: (chai, int, ~msg: string=?) => chai = "lengthOf"
    @send
    external match_: (chai, Js.Re.t, ~msg: string=?) => chai = "match"
    @send
    external string_: (chai, string, ~msg: string=?) => chai = "string"
    @send
    external respondTo: (chai, string, ~msg: string=?) => chai = "respondTo"
    @send
    external closeTo: (chai, float, ~delta: float, ~msg: string=?) => chai = "closeTo"
    @send
    external members: (chai, array<'a>, ~msg: string=?) => chai = "members"
    @send
    external oneOf: (chai, array<'a>, ~msg: string=?) => chai = "oneOf"
    @send
    external change: (chai, array<'a>, ~msg: string=?) => chai = "change"
    @send
    external increase: (chai, Js.t<'a>, string, ~msg: string=?) => chai = "increase"
    @send
    external decrease: (chai, Js.t<'a>, string, ~msg: string=?) => chai = "decrease"
    @send
    external by: (chai, float, ~msg: string=?) => chai = "by"
  }

  @get external ok: chai => chai = "ok"
  @get external true_: chai => chai = "true"
  @get external false_: chai => chai = "false"
  @get external null: chai => chai = ""
  @get external undefined: chai => chai = ""
  @get external nan: chai => chai = "NaN"
  @get external exist: chai => chai = ""
  @get external empty: chai => chai = ""
  @get external arguments: chai => chai = ""
  @get external extensible: chai => chai = ""
  @get external sealed: chai => chai = ""
  @get external frozen: chai => chai = ""
  @get external finite: chai => chai = ""

  @send external keys: (chai, array<string>) => chai = "keys"
  @send external keys': (chai, array<int>) => chai = "keys"
  @send external keys'': (chai, Js.t<'a>) => chai = "keys"
  @send
  external throw: (chai, ~error: Js.Exn.t=?, ~matcher: Js.Re.t=?, ~msg: string=?, unit) => chai =
    "throw"

  /* Provides a better ordering for optional args to avoid the () */
  let a = (~msg=?, value) => Internal.a(value, ~msg?)
  let include_ = (~msg=?, value) => Internal.include_(value, ~msg?)
  let equal = (~msg=?, value) => Internal.equal(value, ~msg?)
  let eql = (~msg=?, value) => Internal.eql(value, ~msg?)
  let above = (~msg=?, value) => Internal.above(value, ~msg?)
  let below = (~msg=?, value) => Internal.below(value, ~msg?)
  let least = (~msg=?, value) => Internal.least(value, ~msg?)
  let most = (~msg=?, value) => Internal.most(value, ~msg?)
  let within = (~msg=?, min, max) => Internal.within(min, max, ~msg?)
  let instanceof = (~msg=?, value) => Internal.instanceof(value, ~msg?)
  let property = (~msg=?, ~value=?, name) => Internal.property(name, ~value?, ~msg?)
  let ownPropertyDescriptor = (~msg=?, ~descriptor=?, name) =>
    Internal.ownPropertyDescriptor(name, ~descriptor?, ~msg?)
  let lengthOf = (~msg=?, value) => Internal.lengthOf(value, ~msg?)
  let match_ = (~msg=?, value) => Internal.match_(value, ~msg?)
  let string_ = (~msg=?, value) => Internal.string_(value, ~msg?)
  let respondTo = (~msg=?, value) => Internal.respondTo(value, ~msg?)
  let closeTo = (~msg=?, value, ~delta) => Internal.closeTo(value, ~delta, ~msg?)
  let members = (~msg=?, value) => Internal.members(value, ~msg?)
  let oneOf = (~msg=?, value) => Internal.oneOf(value, ~msg?)
  let change = (~msg=?, value) => Internal.change(value, ~msg?)
  let decrease = (~msg=?, obj, prop) => Internal.decrease(obj, prop, ~msg?)
  let increase = (~msg=?, obj, prop) => Internal.increase(obj, prop, ~msg?)
  let by = (~msg=?, value) => Internal.by(value, ~msg?)
}

module Combos = {
  /* Some sugar to avoid the boilerplate of piping to much */
  let to_deep_equal = (chai, ~msg=?, value) =>
    chai->Chains.to_->Modifiers.deep->Comparisons.equal(~msg?, value)
  let to_be = to_deep_equal
  let to_be_a = (chai, ~msg=?, value) => chai->Chains.to_->Chains.be->Comparisons.a(~msg?, value)
  let to_be_ok = chai => chai->Chains.to_->Chains.be->Comparisons.ok
  let to_include = (chai, ~msg=?, value) => chai->Chains.to_->Comparisons.include_(~msg?, value)
  let to_equal = (chai, ~msg=?, value) => chai->Chains.to_->Comparisons.equal(~msg?, value)
  let to_eql = (chai, ~msg=?, value) => chai->Chains.to_->Comparisons.eql(~msg?, value)
  let to_be_above = (chai, ~msg=?, value) =>
    chai->Chains.to_->Chains.be->Comparisons.above(~msg?, value)
  let to_be_below = (chai, ~msg=?, value) =>
    chai->Chains.to_->Chains.be->Comparisons.below(~msg?, value)
  let to_be_at_least = (chai, ~msg=?, value) =>
    chai->Chains.to_->Chains.be->Comparisons.least(~msg?, value)
  let to_be_at_most = (chai, ~msg=?, value) =>
    chai->Chains.to_->Chains.be->Comparisons.most(~msg?, value)
  let to_be_within = (chai, ~msg=?, min, max) =>
    chai->Chains.to_->Chains.be->Comparisons.within(~msg?, min, max)
  let to_be_instanceof = (chai, ~msg=?, value) =>
    chai->Chains.to_->Chains.be->Comparisons.instanceof(~msg?, value)

  let to_have_property = (chai, ~msg=?, ~value=?, name) =>
    chai->Chains.to_->Chains.have->Comparisons.property(~msg?, ~value?, name)

  let to_have_own_property_descriptor = (chai, ~msg=?, ~descriptor=?, name) =>
    chai->Chains.to_->Chains.have->Comparisons.ownPropertyDescriptor(~msg?, ~descriptor?, name)

  let to_be_of_length = (chai, ~msg=?, value) =>
    chai->Chains.to_->Chains.be->Chains.of_->Comparisons.lengthOf(~msg?, value)
  let to_match = (chai, ~msg=?, value) => chai->Chains.to_->Comparisons.match_(~msg?, value)
  let to_have_string = (chai, ~msg=?, value) =>
    chai->Chains.to_->Chains.have->Comparisons.string_(~msg?, value)
  let to_throw = (chai, ~msg=?, value) => chai->Chains.to_->Comparisons.throw(~msg?, value)
  let to_respond_to = (chai, ~msg=?, value) => chai->Chains.to_->Comparisons.respondTo(~msg?, value)
  let to_be_close_to = (chai, ~msg=?, ~delta, value) =>
    chai->Chains.to_->Chains.be->Comparisons.closeTo(~msg?, ~delta, value)
  let to_have_members = (chai, ~msg=?, value) =>
    chai->Chains.to_->Chains.have->Comparisons.members(~msg?, value)
  let to_be_one_of = (chai, ~msg=?, value) =>
    chai->Chains.to_->Chains.have->Comparisons.oneOf(~msg?, value)
  let to_have_keys = (chai, value) => chai->Chains.to_->Chains.have->Comparisons.keys(value)
  let to_be_true = chai => chai->Chains.to_->Chains.be->Comparisons.true_
  let to_be_false = chai => chai->Chains.to_->Chains.be->Comparisons.false_
  let to_be_null = chai => chai->Chains.to_->Chains.be->Comparisons.null
  let to_be_undefined = chai => chai->Chains.to_->Chains.be->Comparisons.undefined
  let to_be_NaN = chai => chai->Chains.to_->Chains.be->Comparisons.nan
  let to_exist = chai => chai->Chains.to_->Comparisons.exist
  let to_be_empty = chai => chai->Chains.to_->Chains.be->Comparisons.empty
  let to_be_sealed = chai => chai->Chains.to_->Chains.be->Comparisons.sealed
  let to_be_frozen = chai => chai->Chains.to_->Chains.be->Comparisons.frozen
  let to_be_finite = chai => chai->Chains.to_->Chains.be->Comparisons.finite

  module End = {
    /* Sugar that ignores the result so you don't have to */
    let to_deep_equal = (chai, ~msg=?, value) => chai->to_deep_equal(~msg?, value)->ignore
    let to_be = (chai, ~msg=?, value) => chai->to_be(~msg?, value)->ignore
    let to_be_a = (chai, ~msg=?, value) => chai->to_be_a(~msg?, value)->ignore
    let to_be_ok = chai => chai->to_be_ok->ignore
    let to_include = (chai, ~msg=?, value) => chai->to_include(~msg?, value)->ignore
    let to_equal = (chai, ~msg=?, value) => chai->to_equal(~msg?, value)->ignore
    let to_eql = (chai, ~msg=?, value) => chai->to_eql(~msg?, value)->ignore
    let to_be_above = (chai, ~msg=?, value) => chai->to_be_above(~msg?, value)->ignore
    let to_be_below = (chai, ~msg=?, value) => chai->to_be_below(~msg?, value)->ignore
    let to_be_at_least = (chai, ~msg=?, value) => chai->to_be_at_least(~msg?, value)->ignore
    let to_be_at_most = (chai, ~msg=?, value) => chai->to_be_at_most(~msg?, value)->ignore
    let to_be_within = (chai, ~msg=?, min, max) => chai->to_be_within(~msg?, min, max)->ignore
    let to_be_instanceof = (chai, ~msg=?, value) => chai->to_be_instanceof(~msg?, value)->ignore

    let to_have_property = (chai, ~msg=?, ~value=?, name) =>
      chai->to_have_property(~msg?, ~value?, name)->ignore

    let to_have_own_property_descriptor = (chai, ~msg=?, ~descriptor=?, name) =>
      chai->to_have_own_property_descriptor(~msg?, ~descriptor?, name)->ignore

    let to_be_of_length = (chai, ~msg=?, value) => chai->to_be_of_length(~msg?, value)->ignore
    let to_match = (chai, ~msg=?, value) => chai->to_match(~msg?, value)->ignore
    let to_have_string = (chai, ~msg=?, value) => chai->to_have_string(~msg?, value)->ignore
    let to_throw = (chai, ~msg=?, value) => chai->to_throw(~msg?, value)->ignore
    let to_respond_to = (chai, ~msg=?, value) => chai->to_respond_to(~msg?, value)->ignore
    let to_be_close_to = (chai, ~msg=?, ~delta, value) =>
      chai->to_be_close_to(~msg?, ~delta, value)->ignore
    let to_have_members = (chai, ~msg=?, value) => chai->to_have_members(~msg?, value)->ignore
    let to_be_one_of = (chai, ~msg=?, value) => chai->to_be_one_of(~msg?, value)->ignore
    let to_have_keys = (chai, value) => chai->to_have_keys(value)->ignore
    let to_be_true = chai => chai->to_be_true->ignore
    let to_be_false = chai => chai->to_be_false->ignore
    let to_be_null = chai => chai->to_be_null->ignore
    let to_be_undefined = chai => chai->to_be_undefined->ignore
    let to_be_NaN = chai => chai->to_be_NaN->ignore
    let to_exist = chai => chai->to_exist->ignore
    let to_be_empty = chai => chai->to_be_empty->ignore
    let to_be_sealed = chai => chai->to_be_sealed->ignore
    let to_be_frozen = chai => chai->to_be_frozen->ignore
    let to_be_finite = chai => chai->to_be_finite->ignore
  }
}
